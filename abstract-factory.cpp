#include<iostream>

using namespace std;


class IButton
{
    public:
        virtual void pressed() = 0;
};

class WinButton : public IButton
{
    public:
        void pressed()
        {
            cout << "Windows Button Pressed :) " << endl;
        }
};

class MacButton : public IButton
{
    public:
        void pressed()
        {
            cout << "Mac Button Pressed :) " << endl;
        }
};

class ITextBox
{
    public:
        virtual void showText() = 0;
};

class WinText : public ITextBox
{
    public:
        void showText()
        {
            cout << "Winddows Text Button Shown :)" << endl;
        }
};

class MacText : public ITextBox
{
    public:
        void showText()
        {
            cout << "Mac Text Button Shown :)" << endl;
        }
};



class IFactory
{
    public:
        virtual IButton* CreateButton() = 0;
        virtual ITextBox* CreateTextBox() = 0;
};

class WinFacory : public IFactory
{
    public:
        IButton* CreateButton()
        {
            return new WinButton();
        }

        ITextBox* CreateTextBox()
        {
            return new WinText();
        }

};

class MacFactory : public IFactory
{
    public:
        IButton* CreateButton()
        {
            return new MacButton();
        }

        ITextBox* CreateTextBox()
        {
            return new MacText();
        }

};


class GUIAbstractFactory
{
    public:
        static IFactory* CreateFactory(string osType)
        {
           if(osType == "win")
           {
             return new WinFacory();
           }
           else if(osType == "mac")
           {
                return new MacFactory();
           }
           else
           {
                cout << "Unsupported OS Type :( " << endl;
                cout << "Setting default OS Type : Windows :)" << endl;
                return new WinFacory();
           }
           
        }
};

int main()
{
    string osType;
    cout << "Enter your OS type [win / mac] :" << endl;
    cin >> osType;

    IFactory* fact = GUIAbstractFactory::CreateFactory(osType);

    IButton* button = fact->CreateButton();
    button->pressed();

    ITextBox* textBox = fact->CreateTextBox();
    textBox->showText();

    return 0;
}
