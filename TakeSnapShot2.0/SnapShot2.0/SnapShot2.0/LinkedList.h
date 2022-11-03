
void AddNewDllLinkedList(struct Dll* currentDLL);
void AddNewProcessLinkedList(struct Process* currentProcess);
void AddNewDllToLinkedList(struct Dll* prevDLL, struct Dll* currentDLL);
void AddNewProcessToLinkedList(struct Process* prevProcess, struct Process* currentProcess);
struct SnapShot* SnapShotLinkedList(struct SnapShot* currentSnapShot);

extern int snapShotIDCounter;
