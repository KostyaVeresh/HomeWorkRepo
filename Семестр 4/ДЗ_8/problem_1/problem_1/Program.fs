open System.Net
open System.IO
open Microsoft.FSharp.Control.WebExtensions
open System.Text
open System.Text.RegularExpressions

let reference = new Regex("a href=(\"http://([^\"]*\")|\'[^\']*\')")


let getPage(url: string) =
    async {
        let req = WebRequest.Create(url)
        let! res = req.AsyncGetResponse()
        use htres = res :?> System.Net.HttpWebResponse
        let encStr = htres.CharacterSet
        let enc = Encoding.GetEncoding(encStr)
        use stream = res.GetResponseStream()
        use reader = new StreamReader(stream, enc)
        let code = reader.ReadToEnd()
        return code
    }

let countSymbols (url : string) =
    async {
      let! page = getPage(url)
      return page.Length
    }

let countRefs url =
    async {
        let! page = getPage url
        let matches = reference.Matches(page)
        let links = matches |> Seq.cast<Match> |> Seq.map (fun x -> x.Value.Substring(8, x.Value.Length - 9))
        let workers = Seq.map (fun x -> countSymbols x) links
        let! results = Async.Parallel workers
        let res = Seq.zip links (Array.toSeq results)
        do Seq.iter (fun (l, c) -> printf "link %s has size %i\n" l c) res
    }

[<EntryPoint>]
let main argv =
    Async.RunSynchronously <| countRefs "http://google.com"
    ignore <| System.Console.ReadLine()
    0