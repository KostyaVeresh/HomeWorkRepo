type HashTable(hashsize, calculateHash) =
    let table = [|for i in 1 .. hashsize -> []|]
    member this.AddElem(elem) : unit = 
        table.[calculateHash elem hashsize] <- elem :: table.[calculateHash elem hashsize]
    member this.IfExists(elem) =
        List.exists (fun x -> x = elem) table.[calculateHash elem hashsize]
    member this.DeleteElem(elem) =
        let rec newList list acc is =
            match list with
            | h::t when h <> elem -> newList t (h::acc) is
            | h::t when h = elem && is -> newList t acc false
            | [] -> acc
        table.[calculateHash elem hashsize] <- newList (table.[calculateHash elem hashsize]) [] true  
        
[<EntryPoint>]
let main argv = 
    0