open System

type Operation =
    | Add
    | Sub
    | Mult
    | Div
    | Power

type Expression =
    | Tree of Operation * Expression * Expression
    | Const of int
    | Variable

let differentiation (expression: Expression) =
    let rec derivative (exp: Expression) =
        match exp with
        | Const value -> Const 0
        | Variable -> Const 1
        | Tree(oper, left, right) ->
            match oper with
            | Add | Sub -> Tree(oper, derivative left, derivative right)
            | Mult -> Tree(Add, Tree(oper, derivative left, right), Tree(oper, left, derivative right))
            | Div -> Tree(oper, Tree(Sub, Tree(Mult, derivative left, right), Tree(Mult, left, derivative right)), Tree(Power, right, Const 2 ))
            | Power  ->
                match right with 
                | Const(value) -> Tree(Mult, right, Tree(Mult, Tree(oper, left, Const (value - 1)), derivative left))
                | _ -> failwith "Wrong expression"
    let res = derivative expression
    let rec simple (exp: Expression) =
        match exp with
        | Const value -> Const value
        | Variable -> Variable
        | Tree(oper, left, right) ->
            match oper with
            | Add -> 
                match (right, left) with
                | (Const(0), l) -> simple l
                | (r, Const(0)) -> simple r
                | (r, l) -> Tree(oper, simple r, simple l)
            | Sub -> 
                if left = Const(0) then simple right
                else Tree(oper, simple right, simple left)
            | Mult ->
                match (right, left) with
                | (Const(0), _) | (_, Const(0)) -> Const(0)
                | (r, Const(1)) -> simple r
                | (Const(1), l) -> simple l
                | (r, l) -> Tree(oper, simple r, simple l)
            | Div -> 
                match (right, left) with
                | (Const(0), l) -> Const(0)
                | (r, Const(1)) -> simple r
                | (r, l) -> Tree(oper, simple r, simple l)
            | Power -> 
                match (right, left) with
                | (Const(0), _) -> Const(0)
                | (Const(1), _) -> Const(1)
                | (_, Const(0)) -> Const(1)
                | (r, l) -> Tree(oper, simple r, simple l)
    simple (simple res)

[<EntryPoint>]
let main argv = 
    let exp = Tree(Add, Tree(Mult, Const 2 , Tree(Power, Variable, Const 3)), Const 1 ) // 2*x^3 + 1
    let res = differentiation exp
    ignore(Console.ReadLine())
    0