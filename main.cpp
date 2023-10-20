#include <cstdlib>
#include <iostream>

// uWebSockets
#include <App.h>

static auto default_handler(uWS::HttpResponse<false> *response,
    uWS::HttpRequest *request) -> void {
  response->writeStatus("200 OK");
  response->writeHeader("Content-Type", "text/plain");
  response->end("Hello from Unikraft");
}

int main() {
  const int port = 3000;
  uWS::App app;
  app.any("/*", default_handler);
  app.listen(port, [&port](us_listen_socket_t *listen_socket) -> void {
                     if (listen_socket) {
                       std::cerr << "Listening on port " << port << "\n";
                     }
                   });

  app.run();
  std::cerr << "Failed to listen on port " << port << "\n";
  return EXIT_FAILURE;
}
