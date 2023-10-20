A uWebSockets Example Application on Unikraft
=============================================

[uWebSockets](https://github.com/uNetworking/uWebSockets) is simple, secure &
standards compliant C++ HTTP and WebSockets server for the most demanding of
applications.

Running locally
---------------

```sh
kraft build --jobs 4 --log-type=basic
kraft run --port 3000:3000
curl localhost:3000
```
