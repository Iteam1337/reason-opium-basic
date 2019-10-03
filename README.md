# reasonml-opium-basic

A basic server example using [Opium](https://github.com/rgrinberg/opium) built with ReasonML.

## Getting started

Clone this repository and `cd` into it.

```sh
npm i -g esy@latest
esy
esy start
```

Server runs by default at `http://localhost:3000`

See `src/server.re` for available endpoints.

## Folder structure

| File                             | Description                                                                                                                                                                                 |
| -------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [esy.json](esy.json)             | If you're used to a NPM-like worfklow, `esy.json` is your `package.json` and specifies all dependencies and scripts.                                                                        |
| [\*/dune](src/dune)              | The build system. Specify dependencies and more. [Docs](https://dune.readthedocs.io).                                                                                                       |
| [src/logging.re](src/logging.re) | Sets up our logging. Grabbed from [https://github.com/rgrinberg/opium/blob/master/examples/hello_world_log.ml](https://github.com/rgrinberg/opium/blob/master/examples/hello_world_log.ml). |
| [src/server.re](src/server.re)   | Our main executable (dune).                                                                                                                                                                 |  |

## Dependencies

- [Opium (OCaml)](https://github.com/rgrinberg/opium) - ExpressJS-like web-toolkit.
- [Refmterr (ReasonML)](https://reason-native.com/docs/refmterr/) - Pretty printing for error-messages
- [Tablecloth (Reasonml/OCaml)](https://github.com/darklang/tablecloth) - One of a few base-libraries
- [Cohttp (OCaml)](https://github.com/mirage/ocaml-cohttp/) - Used by Opium for underlying HTTP-implementation.
- [Lwt (OCaml)](https://github.com/ocsigen/lwt) - A promise-implementation for Native OCaml/ReasonML. The `ppx` is used for `await`-like syntax.
