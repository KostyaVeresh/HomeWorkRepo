open System

let palindrom (str: string) =
    let rec palindr first last =
        if first - last = 1 || first = last  then
            true
        else
            if str.Chars(first) = str.Chars(last) then
                palindr (first + 1) (last - 1)
            else
                false
    palindr 0 (str.Length - 1)


[<EntryPoint>]
let main argv = 
    let str = "arozaupalanalapuazora"
    if palindrom str then
        printfn "yes"
    ignore(Console.ReadLine())
    0
