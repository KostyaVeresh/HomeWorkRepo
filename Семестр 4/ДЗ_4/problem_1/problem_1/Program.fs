open System

let brackets (str: string) =
    let list = []
    let openBr char =
        match char with
        | ')' -> '('
        | ']' -> '['
        | '}' -> '{'
        | _ -> ' '
    let rec check (list : char list) num =
        if num = str.Length then list = [] else
        let elem = str.Chars(num)
        match elem with
        | '(' | '[' | '{' -> check ([elem] @ list) (num + 1)
        | ')' | ']' | '}' ->
            match list with
            | [] -> false
            | h :: t -> if h = openBr elem then check (list.Tail) (num + 1) else false
        | _ -> check list (num + 1)
    check [] 0

[<EntryPoint>]
let main argv = 
    let str = "() ({} [] [{ () () }])"
    let res = brackets str
    if res then 
        printfn "is correct" 
    else 
        printfn "is not correct"
    ignore(Console.ReadLine())
    0