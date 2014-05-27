open System
open System.ComponentModel

let array = [|for i in 1 .. 1000000 -> 1|]
let sum =
    let threads = [|for i in 1 .. 100 -> new BackgroundWorker()|]
    let result = ref 0
    let init = List.map (fun i -> 
        threads.[i].DoWork.Add(fun args ->
            let res = Array.sum (Array.sub array i 10000)
            args.Result <- box res)
        threads.[i].RunWorkerCompleted.Add(fun args ->
            result := !result  + unbox args.Result)) [0 .. 99]
    let mutable isThreadWorks = [|for i in 0 .. 99 -> threads.[i].IsBusy|]
    let start = List.map (fun i -> threads.[i].RunWorkerAsync()) [0 .. 99]
    isThreadWorks <- [| for i in 0 .. 99 -> threads.[i].IsBusy |]
    while ((Array.tryFind (fun x -> x = true) isThreadWorks) <> None) do
        isThreadWorks <- [| for i in 0 .. 99 -> threads.[i].IsBusy |]
    result.Value

printfn "%A" (sum)
ignore <| Console.ReadLine()

