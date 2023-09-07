/*
Adapter Pattern

Intent
-------
Convert the interface of a class into another interface clients expect.
Adapter (or Wrapper) lets classes work together that couldn't otherwise because of incompatible interfaces.
Adapter pattern's motivation is that we can reuse existing software if we can modify the interface.

1. Adapter pattern relies on object composition.
2. Client calls operation on Adapter object.
3. Adapter calls Adaptee to carry out the operation.
4. In STL, stack adapted from vector:
    When stack executes push(), underlying vector does vector::push_back().
*/

#include<iostream>

using namespace std;

// Desired Interface (Target Class)
class Rectangle
{
public:
    virtual void Draw() = 0;
    virtual ~Rectangle() = default;
};

// Legacy Component (Adaptee)
class LegacyRectangle
{
    public:
        LegacyRectangle(int X1, int Y1, int X2, int Y2)
        {
            x1 = X1;
            y1 = Y1;
            x2 = X2;
            y2 = Y2;
        }
        void oldDraw()
        {
            cout << "Legacy Rectangle Draw using Point-1 ["<< x1 << ","<< y1 << "] & Point-2 ["<< x2 << "," << y2 <<"]" << endl;
        }
    private:
        int x1;
        int y1;
        int x2;
        int y2;
};

// Adapter Wrapper
class RectangleAdapter:public Rectangle,public LegacyRectangle
{
    public:
        RectangleAdapter(int x,int y,int w,int h):LegacyRectangle(x, y, x+w, y+h)
        {
            
        }

        void Draw()
        {
            cout << "Rectangle Adapter Draw." << endl;
            oldDraw();
        }
};

//Client Code

int main()
{
    int x = 20, y = 50 , w = 300 , h = 200;
    Rectangle *obj = new RectangleAdapter(x,y,w,h);
    obj->Draw();
    return 0;
}