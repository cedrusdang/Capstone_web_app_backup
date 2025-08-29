// This script is for the exe that will execute the environment installation
// And activate the server in both backend and frontend
// Cross platform compatibility is ensured

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Error control
int sh(const std::string& cmd) {
    int rc = std::system(cmd.c_str());
    if (rc != 0) {
        std::cerr << "Command failed: " << cmd << " (rc=" << rc << ")\n";
        std::cerr << "Press Enter to exit...";
        std::cin.get();
        std::exit(1); 
    }
    return rc;
}

int main(){
    // Introduction
    cout << "Copy-right: 2025 - Cedrus Dang, <others should be here" << endl 
    << "Welcome, this is the application of Data Normans - local version" << endl 
    << "We are a team of MS. Data Scientist" << endl
    << "We are coming from the University of Western Australia" << endl
    << "And we are happy to introduce you to our Agentic AI application for SQL to NL tasks." << endl << endl;
    cout << "====================================================================" << endl
    << "This application is a local version for developers that must have Python and Node.js installed." << endl << endl;
    cout << "Press Enter to continue the environment setup or type 'q' then Enter to exit: ";
    string input;
    getline(cin, input);

    if (!input.empty() && (input[0] == 'q' || input[0] == 'Q')) {
        cout << "Exiting setup." << endl;
        return 0;
    } else {
        cout << endl << endl << "Setting up the environment..."<< endl;        

    #ifdef _WIN32
        // Install venv requirements (Windows)
        if (sh("py -m venv .venv && .\\.venv\\Scripts\\python.exe -m pip install -r requirements.txt") != 0) return 1;
        // Install npm dependencies (Windows)
        if (sh("if exist package-lock.json (npm ci) else (npm install)") != 0) return 1;
    #else
        // Install venv requirements (Linux/Mac)
        if (sh("python3 -m venv .venv && ./.venv/bin/python -m pip install -r requirements.txt") != 0) return 1;
        // Install npm dependencies (Linux/Mac)
        if (sh("[ -f package-lock.json ] && npm ci || npm install") != 0) return 1;
    #endif

    cout << "Installation is completed." << endl
    << "Please run the app.exe on Windows or ./app on Mac/Linux to run the application" << endl << endl
    << "Thank you for waiting! Press Enter to continue..." << endl;
    cin.get();
    }
    return 0;
}