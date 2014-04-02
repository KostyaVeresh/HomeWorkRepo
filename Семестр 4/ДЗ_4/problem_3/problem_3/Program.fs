open System
open System.IO

type Record = {Name : string; Number : int}

let phoneDir () =
    let enter () = Console.ReadLine()
    let rec command (list: Record list) = function
        | "0" -> ignore()
        | "1" -> 
            printfn "Enter new name:"
            let name = enter();
            printfn "Enter new phone number:"
            let number = enter() |> int;
            printfn "Enter comand:"
            command (list @ [{Name = name; Number = number}]) (enter())
        | "2" -> 
            printfn "Enter name:" 
            let name = enter()
            match List.tryFind (fun x -> x.Name = name) list with
            | Some x -> printfn "Phone number: %d" x.Number
            | None -> printfn "Not found"
            printfn "Enter comand:"
            command list (enter())
        | "3" -> 
            printfn "Enter number:" 
            let num = enter() |> int
            match List.tryFind (fun x -> x.Number = num) list with
            | Some x -> printfn "Name: %s" x.Name
            | None -> printfn "Not found"
            printfn "Enter comand:"
            command list (enter())
        | "4" ->
            printfn "Records saved to file"
            use sr = new StreamWriter("new_file.txt")
            List.iter (fun x -> sr.WriteLine(x.Name + " " + string x.Number)) list
            sr.Close()
            printfn "Enter comand:"
            command list (enter())
        | "5" ->
            printfn "Records were read from file"
            use sr = new StreamReader("new_file.txt")
            let rec readfile (readList : Record list) =
                if not sr.EndOfStream then
                    let words = (sr.ReadLine()).Split [|' '|]
                    readfile (readList @ [{Name = words.[0]; Number = words.[1] |> int}])  
                else
                    sr.Close()
                    readList         
            printfn "Enter comand:"     
            command (list @ (readfile [])) (enter())
        | _ ->
            printfn "wrong command"
            command list (enter())
    printfn "Enter comand:"
    command [] (enter())

[<EntryPoint>]
let main argv = 
    phoneDir()
    0
