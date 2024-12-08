#ifndef BILLIARDS_HANDLERS_H
#define BILLIARDS_HANDLERS_H
    extern int mouseX, mouseY;

    void display();
    void mousePassiveMove(int x, int y);
    void mouseActivePress(int button, int state, int x, int y);
    void mouseActiveMove(int x, int y);
    void specialKeys(int key, int x, int y);
#endif
