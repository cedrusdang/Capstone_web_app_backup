// This file is responsible for launching the backend and frontend servers
// Cross platform compatibility is ensured using Boost.Process on all platforms
// To end BE FE, press exit on the console

#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Remember to run the Installer before using this App.\nStarting servers...\n";
    // Backend
    std::thread backend([] {
#ifdef _WIN32
        system("cd backend && python manage.py runserver 8000");
#else
        system("cd backend && python3 manage.py runserver 8000 --noreload");
#endif
    });

    // Frontend
    std::thread frontend([] {
        system("cd frontend && npm run dev -- -p 3000");
    });

    // Wait for server to start then open browser
    std::this_thread::sleep_for(std::chrono::seconds(5));
#ifdef _WIN32
    system("start http://localhost:3000");
#elif __APPLE__
    system("open http://localhost:3000");
#else
    system("xdg-open http://localhost:3000");
#endif
    std::cout << "Servers running. Use your UI/servers to stop.\n";

    // Wait for BE/FE to exit
    backend.join();
    frontend.join();
    return 0;
}
