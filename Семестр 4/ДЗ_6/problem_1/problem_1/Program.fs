open System

type RoundBuilder(num : int) =
    member this.Bind (x : float, func : float -> float) = Math.Round(func x, num)
    member this.Return (x : float) = Math.Round(x, num)

let result = RoundBuilder 3 {
    let! a = 2.0 / 12.0
    let! b = 3.5
    return a / b
    }

printf "%A" result
ignore <| Console.ReadLine()