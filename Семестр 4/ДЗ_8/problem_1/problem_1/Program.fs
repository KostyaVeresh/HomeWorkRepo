open System
open System.Net
open System.IO
open Microsoft.FSharp.Control.WebExtensions
open System.Text
open System.Text.RegularExpressions

let reference = new Regex("a href=(\"http://([^\"]*\")|\'[^\']*\')")

let getPage(url:string) =
    async { 
        let req = WebRequest.Create(url)
        let! resp = req.AsyncGetResponse()
        let stream = resp.GetResponseStream()
        let reader = new StreamReader(stream)
        let! html = reader.AsyncReadToEnd()
        return html
        }

let countSymbols (url : string) =
    async {
        let! page = getPage(url)
        return page.Length
        }

let countRefs (url : string) =
    async {
        let! page = getPage(url)
        let refs = reference.Matches(page)
                      |> Seq.cast<Match>
                      |> Seq.map (fun x -> x.Value.Substring(8, x.Value.Length - 9))
        let threads = refs |> Seq.map (fun x -> countSymbols x)
        let! res = Async.Parallel threads
        return Seq.zip refs res
        }

[<EntryPoint>]
let main argv =
    let page = Async.RunSynchronously <| countRefs ("http://microsoft.com/")
    page |> Seq.iter (fun (a,b) -> printfn "%s %d \n" a b)
    ignore <| Console.ReadLine()
    0 