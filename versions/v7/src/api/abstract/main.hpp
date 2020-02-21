/* ... --- NOTE (Lapys) -> Guard against re-implementing this source into the same environment. */
#ifndef LAPYS
    /* Main */
    void Main(...);

    /* Function > ... Main ... */
    BOOL WINAPI DllMain(HINSTANCE DLLHandlerInstance, DWORD forwardingReason, LPVOID reserved) { Lapys::Initiate("DLL"); Lapys::Main(3u, forwardingReason, DLLHandlerInstance, reserved); Lapys::Terminate(false, EXIT_SUCCESS); return EXIT_SUCCESS; }
    int main(int argumentCount, char* argumentVector[]) { Lapys::Initiate(NULL); Lapys::Main(argumentCount, argumentVector); Lapys::Terminate(false, EXIT_SUCCESS); return EXIT_SUCCESS; }
    int wmain(int argumentCount, wchar_t* argumentVector[]) { Lapys::Initiate("Wide Unicode"); Lapys::Main(argumentCount, argumentVector); Lapys::Terminate(false, EXIT_SUCCESS); return EXIT_SUCCESS; }
    int WINAPI WinMain(HINSTANCE handlerInstance, HINSTANCE previousHandlerInstance, LPSTR programInitiationCommandLine, int windowAppearance) { Lapys::Initiate("Windows"); Lapys::Main(4u, programInitiationCommandLine, handlerInstance, previousHandlerInstance, windowAppearance); Lapys::Terminate(false, EXIT_SUCCESS); return EXIT_SUCCESS; }
#endif
