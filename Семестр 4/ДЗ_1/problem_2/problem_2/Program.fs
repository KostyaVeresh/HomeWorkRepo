open System

//Counts the nth Fibonacci number
let rec fibonacci n =
    match n with
    | 0 -> 0
    | 1 -> 1
    | _ -> fibonacci(n - 1) + fibonacci(n - 2)

[<EntryPoint>]
let main n = 
    Console.WriteLine("Test results for first 5 numbers: {0} {1} {2} {3} {4}", fibonacci 1, fibonacci 2, fibonacci 3, fibonacci 4, fibonacci 5);
    Console.ReadLine();
    0
