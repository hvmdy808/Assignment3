#include <iostream>
#include "Image_Class.h"
#include <cmath>
#include <string>
using namespace std;
/*
FCAI - CU
Structured Programming
Assignment 3
Part 1

1- This file contains a small version of photoshop that can apply 15 different filters.
2- The menu loops until the user chooses to exit the program.
3- After applying any filter, the current image will be the with filter applyed and it can be used again and again to apply more and mor filters on it
4- Authors:
    1) Hamdy Mohamed Hamdy - 20230126 - hamdymody901@gmail.com - s17,18 - made the menus, filter 1, filter 4, filter 7, filter 10 and filter 17.
    2) Hady Hassan Ahmed - 20230454 - hadehassan126@gmail.com - s17,18 - made filter 2, filter 5, filter 8, filter 11 and filter 18.
    2) Youssef Mohamed Rafiq - 20230507 - youssef.mohamed.07777@gmail.com - s17,18 - made filter 3, filter 6, filter 9, filter 12 and filter and filter 16.
5- Diagram link: https://drive.google.com/file/d/1YbgHd1EmfPJaw2-9e4J2Mv7nqFoVjATZ/view?usp=sharing
*/

int main();
void menu2(Image &img,  string filename);

////////////////////////////// youssef's part: filters 3, 6, 9, 12 and 16 /////////////////////////////////////////////////


void invert(Image & photo, string fn) {

    for (int i = 0; i < photo.width; ++i) {
        for (int j = 0; j < photo.height; ++j) {

            for (int k = 0; k < photo.channels; ++k) {
                photo (i,j,k)=255- photo(i,j,k);

            }

        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    photo.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                photo.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(photo, filename);
    }
    if(choice3=="b"||choice3=="B"){
        photo.saveImage(fn);
        menu2(photo, fn);
    }

}

void purple(Image &image, string fn) {

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i, j, 0) = image(i, j, 0);
            image(i, j, 1) = image(i, j, 1) * 0.7;
            image(i, j, 2) = image(i, j, 2);
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    image.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                image.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(image, filename);
    }
    if(choice3=="c"||choice3=="C"){
        menu2(image, fn);
    }
    if(choice3=="b"||choice3=="B"){
        image.saveImage(fn);
        menu2(image, fn);
    }
}

void UpFrame(Image& image,int a,int b,int c) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < 100; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void LeftFrame(Image& image,int a,int b,int c) {
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void RightFrame(Image& image,int a,int b,int c) {
    for (int i = image.width - 100; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void DownFrame(Image& image,int a,int b,int c) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 100; j < image.height; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void UpLFrame(Image& image,int a,int b,int c) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < 15; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
    for (int i = 0; i < image.width; ++i) {
        for (int j = 85; j < 100; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void LeftLFrame(Image& image,int a,int b,int c) {
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
    for (int i = 85; i < 100; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void RightLFrame(Image& image,int a,int b,int c) {
    for (int i = image.width - 100; i < image.width - 85; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
    for (int i = image.width - 15; i < image.width ; ++i) {
        for (int j = 0; j < image.height; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void DownLFrame(Image& image,int a,int b,int c) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 100; j < image.height -85; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
    for (int i = 0; i < image.width; ++i) {
        for (int j = image.height - 15; j < image.height ; ++j) {
            image(i,j,0)=a;
            image(i,j,1)=b;
            image(i,j,2)=c;
        }
    }
}

void frames(Image &image, string fn) {
    int x,y;
    int i,j,k;
    cout<<"Choose type from 1-2:"<<endl;
    cout<<"1.simple frame"<<endl<<"2.fancy frame"<<endl;
    cin>>x;
    while (x>2||x<1){
        cout<<"Choose color from 1-2:"<<endl;
        cout<<"1.simple frame"<<endl<<"2.fancy frame"<<endl;
        cin>>x;
    }
    if (x==1) {
        cout << "Choose color from 1-9:" << endl;
        cout << "1.black" << endl << "2.red" << endl << "3.blue" << endl << "4.white" << endl << "5.yellow" << endl
             << "6.cyan" << endl << "7.gray" << endl << "8.green" << endl << "9.magenta" << endl;
        cin >> x;
        while (x > 9 || x < 1) {
            cout << "Choose color from 1-9:" << endl;
            cout << "1.black" << endl << "2.red" << endl << "3.blue" << endl << "4.white" << endl << "5.yellow" << endl
                 << "6.cyan" << endl << "7.gray" << endl << "8.green" << endl << "9.magenta" << endl;
            cin >> x;
        }
        if (x == 1) {
            i = 0, j = 0, k = 0;
        } else if (x == 2) {
            i = 255, j = 0, k = 0;
        } else if (x == 3) {
            i = 0, j = 0, k = 255;
        } else if (x == 4) {
            i = 255, j = 255, k = 255;
        } else if (x == 5) {
            i = 255, j = 255, k = 0;
        } else if (x == 6) {
            i = 0, j = 255, k = 255;
        } else if (x == 7) {
            i = 128, j = 128, k = 128;
        } else if (x == 8) {
            i = 0, j = 255, k = 0;
        } else {
            i = 255, j = 0, k = 255;
        }
        UpFrame(image, i, j, k);
        LeftFrame(image, i, j, k);
        RightFrame(image, i, j, k);
        DownFrame(image, i, j, k);
        string filename;
        string choice3;
        cout<<"Would you like to save the image or exit without saving?"<<endl;
        cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
        cin>>choice3;
        while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
            cout<<"Invalid choice, please, enter a valid choice: "<<endl;
            cin>>choice3;
        }
        if(choice3=="C"||choice3=="c"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(choice3=="a"||choice3=="A"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    image.saveImage(filename);
                    break;
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
            menu2(image, filename);
        }
        if(choice3=="b"||choice3=="B"){
            image.saveImage(fn);
            menu2(image, fn);
        }
    }
    if (x==2){
        cout << "Choose color from 1-9:" << endl;
        cout << "1.black" << endl << "2.red" << endl << "3.blue" << endl << "4.white" << endl << "5.yellow" << endl
             << "6.cyan" << endl << "7.gray" << endl << "8.green" << endl << "9.magenta" << endl;
        cin >> x;
        y=x;
        while (x > 9 || x < 1) {
            cout << "Choose color from 1-9:" << endl;
            cout << "1.black" << endl << "2.red" << endl << "3.blue" << endl << "4.white" << endl << "5.yellow" << endl
                 << "6.cyan" << endl << "7.gray" << endl << "8.green" << endl << "9.magenta" << endl;
            cin >> x;
        }
        if (x == 1) {
            i = 0, j = 0, k = 0;
        } else if (x == 2) {
            i = 255, j = 0, k = 0;
        } else if (x == 3) {
            i = 0, j = 0, k = 255;
        } else if (x == 4) {
            i = 255, j = 255, k = 255;
        } else if (x == 5) {
            i = 255, j = 255, k = 0;
        } else if (x == 6) {
            i = 0, j = 255, k = 255;
        } else if (x == 7) {
            i = 128, j = 128, k = 128;
        } else if (x == 8) {
            i = 0, j = 255, k = 0;
        } else {
            i = 255, j = 0, k = 255;
        }
        UpFrame(image, i, j, k);
        LeftFrame(image, i, j, k);
        RightFrame(image, i, j, k);
        DownFrame(image, i, j, k);
        cout<<"choose from 1-9 except "<<x<<endl;
        cout << "1.black" << endl << "2.red" << endl << "3.blue" << endl << "4.white" << endl << "5.yellow" << endl
             << "6.cyan" << endl << "7.gray" << endl << "8.green" << endl << "9.magenta" << endl;
        cin >> x;
        while (x > 9 || x < 1 || x==y ) {
            cout<<"choose from 1-9 except "<<x<<endl;
            cout << "1.black" << endl << "2.red" << endl << "3.blue" << endl << "4.white" << endl << "5.yellow" << endl
                 << "6.cyan" << endl << "7.gray" << endl << "8.green" << endl << "9.magenta" << endl;
            cin >> x;
        }
        if (x == 1) {
            i = 0, j = 0, k = 0;
        } else if (x == 2) {
            i = 255, j = 0, k = 0;
        } else if (x == 3) {
            i = 0, j = 0, k = 255;
        } else if (x == 4) {
            i = 255, j = 255, k = 255;
        } else if (x == 5) {
            i = 255, j = 255, k = 0;
        } else if (x == 6) {
            i = 0, j = 255, k = 255;
        } else if (x == 7) {
            i = 128, j = 128, k = 128;
        } else if (x == 8) {
            i = 0, j = 255, k = 0;
        } else {
            i = 255, j = 0, k = 255;
        }
        UpLFrame(image, i, j, k);
        LeftLFrame(image, i, j, k);
        RightLFrame(image, i, j, k);
        DownLFrame(image, i, j, k);

        string filename;
        string choice3;
        cout<<"Would you like to save the image or exit without saving?"<<endl;
        cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
        cin>>choice3;
        while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
            cout<<"Invalid choice, please, enter a valid choice: "<<endl;
            cin>>choice3;
        }
        if(choice3=="C"||choice3=="c"){
            string c;
            cout<<"Are you sure that you want to exit without saving?"<<endl;
            cout<<"1- Save changes to a new file and exit"<<endl;
            cout<<"2- Exit without saving"<<endl;
            cin>>c;
            while(c!="1"&&c!="2"){
                cout<<"please enter a valid choice"<<endl;
                cin>>c;
            }
            if(c=="2"){
                cout<<"Thank you for using *Baby Photoshop*";
                exit(0);
            }
            if(c=="1"){
                cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
                cin >> filename;

                while(true){
                    try{
                        image.saveImage(filename);
                        cout<<"Thank you for using *Baby Photoshop*";
                        exit(0);
                    }
                    catch(invalid_argument){
                        cout<<"Please, enter a valid name for the file: ";
                        cin>>filename;
                    }
                }
            }
        }
        if(choice3=="a"||choice3=="A"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    image.saveImage(filename);
                    break;
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
            menu2(image, filename);
        }
        if(choice3=="b"||choice3=="B"){
            image.saveImage(fn);
            menu2(image, fn);
        }
    }

}

void blur(Image & image, string fn) {
    int x;
    cout<<"give me the level of blurring:"<<endl;
    cin>>x;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                int sum = 0;
                int counter = 0;
                for (int l = -x; l < x; ++l) {
                    for (int m = -x; m < x; ++m) {
                        if ((i + l >= 0 && i + l < image.width) && (j + m >= 0 && j + m < image.height)) {
                            counter++;
                            sum += image.getPixel(i + l, j + m, k);
                        }
                    }
                }
                image.setPixel(i, j, k, sum / counter);
            }
        }
    }

    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"1- Save to new image file"<<endl<<"2- Save changes to the same file"<<endl<<"3- Exit"<<endl;
    cin>>choice3;
    while(choice3!="1"&& choice3!="2"&&choice3!="3"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="3"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    image.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="1"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                image.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(image, filename);
    }
    if(choice3=="2"){
        image.saveImage(fn);
        menu2(image, fn);
    }
}

void flip_Vertically(Image & photo) {
    for (int a = 0; a < photo.width; ++a) {
        for (int b = 0; b < photo.height /2; ++b) {
            for (int k = 0; k < 3; ++k) {
                swap(photo(a, b, k), photo(a, photo.height  - 1-b, k));
            }
        }
    }


}

void flip_Horizontally(Image & photo) {
    for (int a = 0; a < photo.height; ++a) {
        for (int b = 0; b < photo.width / 2; ++b) {
            for (int k = 0; k < 3; ++k) {
                swap(photo(b, a, k), photo(photo.width - 1 - b, a, k));
            }
        }
    }
}

void Rotate90degree(Image &rotate, Image &image) {

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                rotate(image.height - j - 1, i, k) = image(i, j, k);
            }
        }
    }
}

void rotate(Image &image, string fn){
    string c;
    cout<<"1- 90 degrees"<<endl;
    cout<<"2- 180 degrees"<<endl;
    cout<<"3- 270 degrees"<<endl;
    cin>>c;
    string filename;
    while(c!="1"&&c!="2"&&c!="3"){
        cout<<"Invalid choice. Please, enter a valid one: "<<endl;
        cin>>c;
    }
    if(c=="1"){
        Image rotate(image.height,image.width);
        Rotate90degree(rotate,image);
        cout<<"Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
        cin>>filename;
        while(true){
            try{
                rotate.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(rotate, filename);
    }
    if(c=="2"){
        flip_Vertically(image);
        flip_Horizontally(image);

        cout<<"Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
        cin>>filename;
        while(true){
            try{
                image.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(image, filename);
    }
    if (c=="3"){
        Image rotate(image.height,image.width);
        Rotate90degree(rotate,image);
        flip_Horizontally(rotate);
        flip_Vertically(rotate);
        cout<<"Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: ";
        cin>>filename;
        while(true){
            try{
                rotate.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(rotate, filename);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////// Hady's part: filters 2, 5, 8, 11 and 18 /////////////////////////////////////////////////

void skew_Horizontally(Image &image)
{
    cout << "Please enter degree to skew right:";
    float degree, ang;
    cin >> degree;
    ang = (degree * M_PI) / 180.0;
    double M = tan(ang);
    Image photo(image.width + image.height * cos(ang), image.height * sin(ang));
    double ratio = (float)image.height / photo.height;
    for (int i =0 ;i<photo.width;i++){
        for (int j=0;j<photo.height;j++){
            for(int k=0;k<3;k++){
                photo(i,j,k)=255;
            }
        }
    }
    for (int a = 0; a < photo.width; a++)
    {
        for (int b = 0; b < photo.height; b++)
        {
            if ((b < M * a) && b > (M * a - M * image.width))
            {
                for (int c = 0; c < 3; c++)
                {
                    photo(a, b, c) = image(image.width - (a - b / M), b * ratio, c);
                }
            }
        }
    }
    Image photo2(photo.width, photo.height);
    for (int a = 1; a < photo2.width; a++)
    {
        for (int b = 1; b < photo2.height; b++)
        {
            for (int c = 0; c < 3; c++)
            {
                photo2(a, b, c) = photo(photo.width - a, b, c);
            }
        }
    }

    string filename;
    cout<<"Please, enter a name for the file: "<<endl;
    cin>>filename;

    while(true){
        try{
            photo2.saveImage(filename);
            menu2(photo2, filename);
        }
        catch(invalid_argument){
            cout<<"Please, enter a valid name for the file: ";
            cin>>filename;
        }
    }

}

void resize(Image & image , string fn) {

    int Width, Height;
    cout <<"please enter Width:";
    cin >> Width;
    cout <<"please enter Height:";
    cin >> Height;
    Image resize(Width, Height);


    double ratioX = double(image.width) / Width;
    double ratioY = double(image.height) / Height;

    for (int i = 0; i < Width; i++) {
        for (int j = 0; j < Height; j++) {
            int ScrX = round(i * ratioX);
            int ScrY = round(j * ratioY);

            if (ScrX < 0)
            {
                ScrX = 0;
            }
            else if (ScrX >= image.width)
            {
                ScrX = image.width - 1;
            }

            if (ScrY < 0)
            {
                ScrY = 0;
            }
            else if (ScrY >= image.height)
            {
                ScrY = image.height - 1;
            }


            for (int k = 0; k < image.channels; k++) {
                resize.setPixel(i, j, k, image.getPixel(ScrX, ScrY, k));
            }
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    image.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                image.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(image, filename);
    }
    if(choice3=="c"||choice3=="C"){
        menu2(image, fn);
    }
    if(choice3=="b"||choice3=="B"){
        image.saveImage(fn);
        menu2(image, fn);
    }
}

void cropImage(Image& img, string fn) {
    int start_X , start_Y, width, height;
    cout<<"Enter the starting point X: "<<endl;
    cin>>start_X;
    cout<<"Enter the starting point Y: "<<endl;
    cin>>start_Y;
    cout<<"Enter the first dimension of the cropped image: "<<endl;
    cin>>width;
    cout<<"Enter the second dimension of the cropped image: "<<endl;
    cin>>height;
    while (start_X < 0 || start_Y < 0 || (start_X) + (width) > img.width || (start_Y) + (height) > img.height) {
        cout << "Error: Cropping area exceeds image boundaries. Please, try again." << endl;
        cout<<"Enter the starting point X: "<<endl;
        cin>>start_X;
        cout<<"Enter the starting point Y: "<<endl;
        cin>>start_Y;
        cout<<"Enter the first dimension of the cropped image: "<<endl;
        cin>>width;
        cout<<"Enter the second dimension of the cropped image: "<<endl;
        cin>>height;
    }

    Image croppedImg((width), (height));

    for (int i = 0; i < (width); ++i) {
        for (int j = 0; j < (height); ++j) {
            for (int channel = 0; channel < 3; ++channel) {
                croppedImg(i, j, channel) = img((start_X )+ i, (start_Y) + j, channel);
            }
        }
    }
    img = croppedImg;
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"1- Save to new image file"<<endl<<"2- Save changes to the same file"<<endl<<"3- Exit"<<endl;
    cin>>choice3;
    while(choice3!="1"&& choice3!="2"&&choice3!="3"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="3"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    img.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="1"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                img.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(img, filename);
    }
    if(choice3=="2"){
        img.saveImage(fn);
        menu2(img, fn);
    }
}

void flip_Horizontal(Image & photo, string fn) {
    for (int a = 0; a < photo.height; ++a) {
        for (int b = 0; b < photo.width / 2; ++b) {
            for (int k = 0; k < 3; ++k) {
                swap(photo(b,a, k), photo(photo.width - 1 - b, a, k));
            }
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    photo.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                photo.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(photo, filename);
    }
    if(choice3=="b"||choice3=="B"){
        photo.saveImage(fn);
        menu2(photo, fn);
    }
}

void flip_Vertical(Image & photo, string fn) {
    for (int a = 0; a < photo.width; ++a) {
        for (int b = 0; b < photo.height / 2; ++b) {
            for (int k = 0; k < 3; ++k) {
                swap(photo(a, b, k), photo(a, photo.height - 1 - b, k));
            }
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    photo.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                photo.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(photo, filename);
    }
    if(choice3=="b"||choice3=="B"){
        photo.saveImage(fn);
        menu2(photo, fn);
    }
}

void flip(Image & photo, string name) {
    string c;
    cout << "1) flip Horizontal\n2) flip Vertical\n";
    cin >> c;
    while(c!="1" && c !="2"){
        cout << "Invalid choice, please, enter the choice again: ";
        cin>>c;
    }
    if (c == "1") {
        flip_Horizontal(photo, name);
    } else if (c == "2") {
        flip_Vertical(photo, name);
    }

}

void convertToBlackAndWhite(Image &image, string fn) {
    // Convert the image to grayscale
    for (int x = 0; x < image.width; ++x) {
        for (int y = 0; y < image.height; ++y) {
            // Calculate luminance value (grayscale) for the pixel
            unsigned int luminance = 0;
            for (int channel = 0; channel < 3; ++channel) {
                luminance += image(x, y, channel); // Accumulate pixel values
            }
            luminance /= 3; // Calculate average luminance

            // Set pixel to black or white based on luminance threshold
            if (luminance < 128) {
                // Set pixel to black
                for (int channel = 0; channel < 3; ++channel) {
                    image(x, y, channel) = 0;
                }
            } else {
                // Set pixel to white
                for (int channel = 0; channel < 3; ++channel) {
                    image(x, y, channel) = 255;
                }
            }
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save the changes to a new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="c"||choice3=="C"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    image.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                image.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(image, filename);
    }
    if(choice3=="b"||choice3=="B"){
        image.saveImage(fn);
        menu2(image, fn);
    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////// Hamdy's part: filters 1, 4, 7, 10, 17 and menus /////////////////////////////////////////////////

void infrared(Image &img, string fn){
    for(int i=0; i<img.width; ++i){
        for(int j=0; j<img.height; ++j){
            unsigned int luminance=0;
            for (int channel = 0; channel < 3; ++channel){
                luminance += img(i, j, channel);
            }
            luminance /= 3;
            img(i,j,0)=luminance;
            img(i,j,1)=luminance;
            img(i,j,2)=luminance;
        }
    }

    for(int i=0; i<img.width; ++i){
        for(int j=0; j<img.height; ++j){
            for (int k = 0; k < img.channels; ++k) {
                img (i,j,k)=255- img(i,j,k);
            }

        }
    }

    for(int i=0; i<img.width; ++i){
        for(int j=0; j<img.height; ++j){
            if(img(i,j,0)+90>255){
                img(i,j,0)=255;
            }
            if(img(i,j,0)+90<=255){
                img(i,j,0)+=90;
            }
            if(img(i,j,1)-90<0){
                img(i,j,1)=0;
            }
            if(img(i,j,1)-90>=0){
                img(i,j,1)-=90;
            }
            if(img(i,j,2)-90<0){
                img(i,j,2)=0;
            }
            if(img(i,j,2)-90>=0){
                img(i,j,2)-=90;
            }
        }
    }




    for(int i=0; i<img.width; ++i) {
        for(int j=0; j< img.height; ++j){
            for(int k=0 ; k<3; ++k){
                if(img(i, j, k)>127){
                    img(i, j, k)=255;
                }
                else{
                    img(i, j, k)=img(i, j, k)*2;
                }
            }
        }
    }

    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    img.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                img.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(img, filename);
    }
    if(choice3=="c"||choice3=="C"){
        menu2(img, fn);
    }
    if(choice3=="b"||choice3=="B"){
        img.saveImage(fn);
        menu2(img, fn);
    }
}

void edgedetection(Image &image, string fn){
    int h_kernel[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
    int v_kernel[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
    Image temp_image(image.width, image.height);

    for(int i=0; i<image.width; ++i){
        for(int j=0; j<image.height; ++j){
            unsigned int luminance=0;
            for (int channel = 0; channel < 3; ++channel) {
                luminance += image(i, j, channel);
            }
            luminance /= 3;
            image(i,j,0)=luminance;
            image(i,j,1)=luminance;
            image(i,j,2)=luminance;
        }
    }

    for(int x=1; x<image.width-1; ++x){
        for(int y=1; y<image.height-1; ++y){
            int h_gradiant=0;
            int v_gradiant=0;
            for(int a =-1; a<2;++a){
                for(int b=-1; b<2; ++b){
                    h_gradiant+=h_kernel[a+1][b+1]*image(x+a,y+b,0);
                    v_gradiant+=v_kernel[a+1][b+1]*image(x+a,y+b,0);
                }
            }
            int g_magnitude=sqrt(h_gradiant * h_gradiant + v_gradiant * v_gradiant);
            if(g_magnitude>=120){
                g_magnitude=0;
            }else{
                g_magnitude=255;
            }
            temp_image(x,y,0)=g_magnitude;
            temp_image(x,y,1)=g_magnitude;
            temp_image(x,y,2)=g_magnitude;
        }
    }

    for(int i=0; i<image.width; ++i){
        for(int j=0; j<image.height; ++j){
            for(int k=0; k<3; ++k){
                image(i,j,k)=temp_image(i,j,k);
            }
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save the changes to a new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="c"||choice3=="C"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    image.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                image.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(image, filename);
    }
    if(choice3=="b"||choice3=="B"){
        image.saveImage(fn);
        menu2(image, fn);
    }


}

Image resizeForMerge(Image photo, int w, int h){
    Image resized(w, h);
    double ratioX = double(photo.width) / w;
    double ratioY = double(photo.height) / h;

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            int ScrX = round(i * ratioX);
            int ScrY = round(j * ratioY);

            if (ScrX < 0)
            {
                ScrX = 0;
            }
            else if (ScrX >= photo.width)
            {
                ScrX = photo.width - 1;
            }

            if (ScrY < 0)
            {
                ScrY = 0;
            }
            else if (ScrY >= photo.height)
            {
                ScrY = photo.height - 1;
            }


            for (int k = 0; k < photo.channels; k++) {
                resized.setPixel(i, j, k, photo.getPixel(ScrX, ScrY, k));
            }
        }
    }
    return resized;
}

void merge(Image  img1){
    Image image2;
    string fn2;
    cout << "Enter the name of the second image file: ";
    cin>>fn2;
    while (true){
        try{
            image2.loadNewImage(fn2);
            string c;
            string newfn;
            int wid, hei;
            cout<<"What merging method do you want to apply?"<<endl;
            cout<<"1- Resize the smaller image or both images to the biggest height and the biggest width and then merge."<<endl;
            cout<<"2- Merge the common area of the smaller width and the smaller height."<<endl;
            cout<<"Enter your choice: "<<endl;
            cin>>c;
            while(c!="1"&&c!="2"){
                cout<<"Please, enter a valid choice: "<<endl;
                cin>>c;
            }
            if (c=="1") {
                wid=max(img1.width, image2.width);
                hei = max(img1.height, image2.height);
                Image resized_img1=resizeForMerge(img1, wid, hei);
                Image resized_img2=resizeForMerge(image2, wid, hei);
                Image merged(wid, hei);
                for(int i=0; i<wid; ++i){
                    for(int j=0; j<hei; ++j ){
                        for(int k=0; k<3; ++k){
                            unsigned int avg=(resized_img1.getPixel(i,j,k)+resized_img2.getPixel(i,j,k))/2;
                            merged.setPixel(i, j, k, avg);
                        }
                    }
                }
                cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
                cin >> newfn;
                while(true){
                    try{
                        merged.saveImage(newfn);
                        break;
                    }
                    catch(invalid_argument){
                        cout<<"Please, enter a valid name for the file: ";
                        cin>>newfn;
                    }
                }
                menu2(merged, newfn);
            }
            if(c=="2"){
                wid=min(img1.width, image2.width);
                hei=min(img1.height, image2.height);
                Image merged(wid, hei);
                for(int i=0; i<wid; ++i){
                    for(int j=0; j<hei; ++j ){
                        for(int k=0; k<3; ++k){
                            unsigned int avg=(img1.getPixel(i,j,k)+image2.getPixel(i,j,k))/2;
                            merged.setPixel(i, j, k, avg);
                        }
                    }
                }
                cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
                cin >> newfn;
                while(true){
                    try{
                        merged.saveImage(newfn);
                        break;
                    }
                    catch(invalid_argument){
                        cout<<"Please, enter a valid name for the file: ";
                        cin>>newfn;
                    }
                }
                menu2(merged, newfn);
            }
        }
        catch(invalid_argument){
            cout<<"Please, enter a valid name for the file: "<<endl;
            cin>>fn2;
        }
    }




}

void dark(Image & img, string fn){
    for(int i=0; i<img.width; ++i) {
        for(int j=0; j< img.height; ++j){
            for(int k=0 ; k<3; ++k){
                img(i, j, k)=img(i, j, k)*0.5;
            }
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"1- Save to new image file"<<endl<<"2- Save changes to the same file"<<endl<<"3- Exit"<<endl;
    cin>>choice3;
    while(choice3!="1"&& choice3!="2"&&choice3!="3"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="3"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    img.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="1"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                img.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(img, filename);
    }
    if(choice3=="2"){
        img.saveImage(fn);
        menu2(img, fn);
    }
}

void light(Image & img, string fn){
    for(int i=0; i<img.width; ++i) {
        for(int j=0; j< img.height; ++j){
            for(int k=0 ; k<3; ++k){
                if(img(i, j, k)>170){
                    img(i, j, k)=255;
                }
                else{
                    img(i, j, k)=img(i, j, k)*1.5;
                }
            }
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    img.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                img.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(img, filename);
    }
    if(choice3=="c"||choice3=="C"){
        menu2(img, fn);
    }
    if(choice3=="b"||choice3=="B"){
        img.saveImage(fn);
        menu2(img, fn);
    }

}

void dark_or_light(Image & img, string name) {
    cout<<"A)  Lighter\nB)  Darker\n";
    string c;
    cin>>c;
    while(c!="a"&&c!="b"&&c!="A"&& c!="B"){
        cout<<"Invalid choice, please enter a valid choice: ";
        cin>>c;
    }
    if (c=="A"||c=="a"){
        light(img, name);
    }
    else if(c=="b"|| c=="B"){
        dark(img, name);
    }
}

void grayScale(Image & photo, string fn){
    for(int i=0; i<photo.width; ++i){
        for(int j=0; j<photo.height; ++j){
            unsigned int luminance=0;
            for (int channel = 0; channel < 3; ++channel) {
                luminance += photo(i, j, channel);
            }
            luminance /= 3;
            photo(i,j,0)=luminance;
            photo(i,j,1)=luminance;
            photo(i,j,2)=luminance;
        }
    }
    string filename;
    string choice3;
    cout<<"Would you like to save the image or exit without saving?"<<endl;
    cout<<"A) Save to new image file"<<endl<<"B) Save changes to the same file"<<endl<<"C) Exit"<<endl;
    cin>>choice3;
    while(choice3!="A"&& choice3!="B"&&choice3!="a"&& choice3!="b"&&choice3!="c"&&choice3!="C"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice3;
    }
    if(choice3=="C"||choice3=="c"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    photo.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if(choice3=="a"||choice3=="A"){
        cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin >> filename;

        while(true){
            try{
                photo.saveImage(filename);
                break;
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: ";
                cin>>filename;
            }
        }
        menu2(photo, filename);
    }

    if(choice3=="b"||choice3=="B"){
        photo.saveImage(fn);
        menu2(photo, fn);
    }
}

void menu2(Image &img,  string filename){
    string choice2;
    string NewFN;
    cout<<"1- Load a new image"<<endl;
    cout<<"2- Filter1: Black and white"<<endl;
    cout<<"3- Filter2: Flip"<<endl;
    cout<<"4- Filter3: Invert"<<endl;
    cout<<"5- Filter4: Grayscale"<<endl;
    cout<<"6- Filter5: Darken or lighten"<<endl;
    cout<<"7- Filter6: Crop"<<endl;
    cout<<"8- Filter7: Resize"<<endl;
    cout<<"9- Filter8: Merge"<<endl;
    cout<<"10- Filter9: Rotate"<<endl;
    cout<<"11- Filter10: Image skewing"<<endl;
    cout<<"12- Filter11: Edge detection"<<endl;
    cout<<"13- filter12: Frame"<<endl;
    cout<<"14- Filter13: Infra red"<<endl;
    cout<<"15- Filter14: Bluring"<<endl;
    cout<<"16- Filter15: Purple"<<endl;
    cout<<"17- Save the current image"<<endl;
    cout<<"18- Exit"<<endl;
    cin>>choice2;
    while(choice2!="1"&& choice2!="2"&& choice2!="3"&& choice2!="4"&& choice2!="5"&&choice2!="6"&&choice2!="7"&&choice2!="8"&&choice2!="9"&&choice2!="10"&&choice2!="11"&&choice2!="12"&&choice2!="13"&&choice2!="14"&&choice2!="15"&&choice2!="16"&&choice2!="17"&&choice2!="18"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice2;
    }

    if(choice2=="2"){
        convertToBlackAndWhite(img, filename);
    }
    if(choice2=="3"){
        flip(img, filename);
    }
    if(choice2=="4"){
        invert(img, filename);
    }
    if(choice2=="5"){
        grayScale(img, filename);
    }
    if(choice2=="6"){
        dark_or_light(img, filename);
    }
    if(choice2=="7"){
        cropImage(img,filename);
    }
    if(choice2=="8"){
        resize(img, filename);
    }
    if(choice2=="9"){
        merge(img);
    }
    if(choice2=="10"){
        rotate(img, filename);
    }
    if(choice2=="11"){
        skew_Horizontally(img);
    }
    if(choice2=="12"){
        edgedetection(img, filename);
    }
    if(choice2=="13"){
        frames(img, filename);
    }
    if(choice2=="14"){
        infrared(img, filename);
    }
    if(choice2=="15"){
        blur(img, filename);
    }
    if(choice2=="16"){
        purple(img, filename);
    }
    if(choice2=="18"){
        string c;
        cout<<"Are you sure that you want to exit without saving?"<<endl;
        cout<<"1- Save changes to a new file and exit"<<endl;
        cout<<"2- Exit without saving"<<endl;
        cin>>c;
        while(c!="1"&&c!="2"){
            cout<<"please enter a valid choice"<<endl;
            cin>>c;
        }
        if(c=="2"){
            cout<<"Thank you for using *Baby Photoshop*";
            exit(0);
        }
        if(c=="1"){
            cout << "Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin >> filename;

            while(true){
                try{
                    img.saveImage(filename);
                    cout<<"Thank you for using *Baby Photoshop*";
                    exit(0);
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: ";
                    cin>>filename;
                }
            }
        }
    }
    if (choice2=="17"){
        cout<<"Please, enter image name to store new image and specify extension .jpg, .bmp, .png, .tga: "<<endl;
        cin>>NewFN;

        while(true){
            try{
                img.saveImage(NewFN);
                menu2(img, NewFN);
            }
            catch(invalid_argument){
                cout<<"Please, enter a valid name for the file: "<<endl;
                cin>>NewFN;
            }
        }
    }
    if(choice2 == "1") {
        string c;
        cout << "Are you sure that you want to load an image without saving last changes?" << endl;
        cout << "1- Save changes to a new file and load another one" << endl;
        cout << "2- Load without saving" << endl;
        cin >> c;
        while (c != "1" && c != "2") {
            cout << "please enter a valid choice" << endl;
            cin >> c;
        }
        if (c == "2") {
            cout<< "Please, enter the name of the nem image you want to load and specify extension .jpg, .bmp, .png, .tga: "<< endl;
            cin >> NewFN;
            while (true) {
                try {
                    img.loadNewImage(NewFN);
                    menu2(img, NewFN);
                }
                catch (invalid_argument) {
                    cout << "Please, enter a valid name for the file: " << endl;
                    cin >> NewFN;
                }
            }
        }
        if(c=="1"){
            cout<<"Please, enter image name to store the last changes and specify extension .jpg, .bmp, .png, .tga: "<<endl;
            cin>>NewFN;

            while(true){
                try{
                    img.saveImage(NewFN);
                    cout<< "Please, enter the name of the nem image you want to load and specify extension .jpg, .bmp, .png, .tga: "<< endl;
                    cin >> NewFN;
                    while (true) {
                        try {
                            img.loadNewImage(NewFN);
                            menu2(img, NewFN);
                        }
                        catch (invalid_argument) {
                            cout << "Please, enter a valid name for the file: " << endl;
                            cin >> NewFN;
                        }
                    }
                }
                catch(invalid_argument){
                    cout<<"Please, enter a valid name for the file: "<<endl;
                    cin>>NewFN;
                }
            }
        }
    }
}

int main(){
    cout<<"Hello! Welcome to *Baby Photoshop*"<<endl;
    cout<<"Please, enter your choice: "<<endl;
    cout<<"1- Load an image and apply filters."<<endl;
    cout<<"2- Exit."<<endl;
    string choice;
    cin>>choice;
    string fileName;
    string choice2;
    Image img;

    while(choice!="1"&& choice!="2"){
        cout<<"Invalid choice, please, enter a valid choice: "<<endl;
        cin>>choice;
    }
    if (choice=="2"){
        cout<<"Thank you for using *Baby Photoshop*";
        exit(0);
    }
    if(choice=="1"){
        cout<<"Please, enter the name of the image you want to load and specify extension .jpg, .bmp, .png, .tga: ";
        cin>>fileName;
    }
    while (true){

        try{
            img.loadNewImage(fileName);
            break;
        }
        catch(invalid_argument){
            cout<<"Please, enter a valid name for the file: "<<endl;
            cin>>fileName;
        }
    }
    menu2(img, fileName);

}

/////////////////////////////////////////////////////////////////////////////////////////
