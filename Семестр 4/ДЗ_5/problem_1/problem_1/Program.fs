type OperSystem =
    | Windows
    | Linux
    | Mac

type Computer(os, virused) =
    let mutable virused = virused
    let rand = new System.Random()
    let syst = os
    member this.IsVirused = virused
    member this.OperSyst = syst
    member this.Infect() =
        let value = rand.Next(0, 100)
        match syst with
        | Windows -> 
            if value < 50 then virused <- true
        | Linux -> 
            if value < 50 then virused <- true
        | Mac -> 
            if value < 50 then virused <- true

type Network(adjacencyMatrix : int[][], computerOS : OperSystem[], virusedComputers : bool[]) =
    let adjacencyMatrix = adjacencyMatrix
    let computersOfNet = [|for i in 1 .. computerOS.Length -> new Computer(computerOS.[i], virusedComputers.[i])|]
    let TryToInfect =
        let canBeVirused = [|for i in 1 .. computersOfNet.Length -> false|]
        let rec findVirused acc1 =
            match acc1 with
            | x when x = computersOfNet.Length + 1 -> ignore()
            | _ -> 
                if computersOfNet.[acc1].IsVirused then 
                    let rec setIfCanBeVirused acc2 =
                        match acc2 with
                        | x when x = computersOfNet.Length + 1 -> ignore()
                        | _ -> 
                            if adjacencyMatrix.[acc1].[acc2] = 1 then canBeVirused.[acc2] <- true
                            setIfCanBeVirused (acc2 + 1)
                    setIfCanBeVirused 1
                findVirused (acc1 + 1)
        findVirused 1
        canBeVirused

    member this.ComputersOfNet = computersOfNet
    member this.NextState() =
        let rec state acc =
            match acc with
            | x when x = computersOfNet.Length + 1 -> ignore()
            | _ -> 
                if TryToInfect.[acc] then computersOfNet.[acc].Infect()
                state (acc + 1)
        state 1


[<EntryPoint>]
let main argv = 
    printfn "%A" argv
    0
