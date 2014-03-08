open System

//Counts factorial of natural number
let rec fact n =
    match n with
    | 0 -> 1
    | _ -> fact(n - 1) * n

[<EntryPoint>]
let main n = 
    //let res = fact 5
    //printfn "Test results for 5: %d" res
    Console.WriteLine("Test results for 0,1,5,6: {0} {1} {2} {3}", fact 0, fact 1, fact 5, fact 6)
    Console.ReadLine()
    0
