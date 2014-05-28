open System
open System.IO

type Record = {Name : string; Number : int}

let phoneDir () =
    let enter () = Console.ReadLine()
    let enterNum () = int(enter())
    let getName x = x.Name
    let getNum x = x.Number

    let find (enterStr : string) (getIdFunc) (get1) (list: Record list) (get2: Record -> 'b) (str: string)  =
        Console.WriteLine(enterStr)
        let id = getIdFunc()
        match List.tryFind (fun x -> get1 x = id) list with
        | Some x -> Console.WriteLine(str, get2(x));
        | None -> printfn "Not found"

    let enterCommand() = 
        printfn "Enter command: 1 - to add new record, 2 - to find phone number, 3 - to find name
        4 - to save records, 5- to read records"
    let rec command (list: Record list) = function
        | "0" -> ignore()
        | "1" -> 
            printfn "Enter new name:"
            let name = enter();
            printfn "Enter new phone number:"
            let number = enter() |> int;
            enterCommand()
            command ({Name = name; Number = number} :: list) (enter())
        | "2" -> 
            find ("Enter name") enter getName list getNum ("Number: ") 
            enterCommand()
            command list (enter())
        | "3" -> 
            find ("Enter phone") enterNum getNum list getName ("Name: ")
            enterCommand()
            command list (enter())
        | "4" ->
            printfn "Records saved to file"
            use sr = new StreamWriter("new_file.txt")
            List.iter (fun x -> sr.WriteLine(x.Name + " " + string x.Number)) list
            sr.Close()
            enterCommand()
            command list (enter())
        | "5" ->
            printfn "Records were read from file"
            use sr = new StreamReader("new_file.txt")
            let rec readfile (readList : Record list) =
                if not sr.EndOfStream then
                    let words = (sr.ReadLine()).Split [|' '|]
                    readfile ({Name = words.[0]; Number = words.[1] |> int} :: readList)  
                else
                    sr.Close()
                    readList         
            enterCommand()    
            command (list @ (readfile [])) (enter())
        | _ ->
            printfn "wrong command"
            command list (enter())
    
    command [] (enter())

[<EntryPoint>]
let main argv = 
    phoneDir()
    0
