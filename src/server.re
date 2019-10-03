open Opium.Std;
open Lwt.Infix;

let auth_header =
  post("/auth", req => {
    let result =
      Cohttp.Header.get(req |> Request.headers, "Authorization")
      |> Tablecloth.Option.withDefault(~default="None");

    `String(result) |> respond';
  });

let json_response =
  get("/json", _req => {
    let json =
      `Assoc([("name", `String("Elizabeth")), ("height", `Int(163))]);

    `Json(json) |> respond';
  });

let hello_param =
  get("/hello/:name", req =>
    `String("Hello " ++ param(req, "name")) |> respond'
  );

let cat_info =
  get("/cat", _req => {
    let%lwt body =
      Cohttp_lwt_unix.Client.get(
        Uri.of_string("http://cat-fact.herokuapp.com/facts/random"),
      )
      >>= (
        ((_resp, body)) => {
          body |> Cohttp_lwt.Body.to_string >|= (body => body);
        }
      );

    `String(body) |> respond';
  });

let hello_world =
  get("/", _req => `Html("<h1>Hello World!</h1>") |> respond');

let () = {
  let app =
    App.empty
    |> middleware(Logging.logger)
    |> auth_header
    |> hello_param
    |> json_response
    |> cat_info
    |> hello_world
    |> App.run_command';

  switch (app) {
  | `Ok(app) =>
    let s =
      Logging.log_reporter()
      >>= (
        r => {
          Logs.set_reporter(r);
          Logs.set_level(Some(Logs.Info));
          app;
        }
      );
    ignore(Lwt_main.run(s));
  | `Error => exit(1)
  | `Not_running => exit(0)
  };
};
