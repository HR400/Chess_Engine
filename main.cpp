#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include <iostream>
#include<cmath>
#include <ctime>
//Opengl is a state machine . Tell it before you can actually change it 

//Global var for window dimensions
int width{800};
int height {600};

//global variables for vertex position
double x_1{},x_2{},x_3{};
double y_1{},y_2{},y_3{};


//global variables for vertex velocities
double vx_1{},vx_2{},vx_3{};

double vy_1{},vy_2{},vy_3{};


double t{0};


void init_physics(){
//seed the random num generator
srand(static_cast<unsigned int >(time(NULL)));

x_1=rand() % width;
x_2=rand() % width;
x_3=rand() % width;

y_1=rand() % height;
y_2=rand() % height;
y_3=rand() % height;

vx_1= 0.005* (rand() %width)-0.0025;
vx_2= 0.005* (rand() %width)-0.0025;
vx_3= 0.005* (rand() %width)-0.0025;
vy_1= 0.005* (rand() %height)-0.0025;
vy_2= 0.005* (rand() %height)-0.0025;
vy_3= 0.005* (rand() %height)-0.0025;

}
int main(){
    
    if(!glfwInit()){
        std::cerr<<"Failed to initiallize GLFW"<<std::endl;
        return -1;
    }
    
    //what version of opengl is used , currently legacy immediate mode
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,1);
    
    //create a windowed mode window 
    GLFWwindow* window =glfwCreateWindow(width,height,"Chess Engine",NULL,NULL);
    if(!window){
        std::cerr<<"Failded to create window "<<std::endl;
        glfwTerminate();
        return -1;
    }
    //keeps calling the window thread 
    glfwMakeContextCurrent(window);

    // initialize random geo vectors

    init_physics();


    //set a 2d projection matrix
    glMatrixMode(GL_PROJECTION);//adjust camera lens(to display 3d in 2d window)
    glLoadIdentity();//clears active matrix stack and replace it identity matrix
    //screen boundaries
    glOrtho(0.0,width,height,0.0, -1.0,1.0);//left , right, bottom,top,near,far
    
    glMatrixMode(GL_MODELVIEW);//switch from camera to object
    glLoadIdentity();//again clear the cord, so that drawing starts from(0,0)


    //engine loop
    while(!glfwWindowShouldClose(window))//keep checking window flag and what should it perform during that time 
    {
        //clear background screen black
        glClearColor(0.0f , 0.0f , 0.0f ,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //tell open gl to begin drawing a triangle
        glBegin(GL_TRIANGLES);
        
            //vertex1
            //SET RBG OF EACH VERTEX
            glColor3f(sin(t*0.9),cos(t*0.4),1);
            glVertex2f(x_1,y_1);

            //vertex2
           glColor3f(1,sin(t*0.8),cos(t*0.5));
           glVertex2f(x_2,y_2);

            //vertex3
            glColor3f(sin(t*0.7),1,cos(t*0.6));
            glVertex2f(x_3,y_3);
        glEnd();


        //Physics logic
        //position is contantly updated by constant velocity 

        x_1+=vx_1;
        x_2+=vx_2;
        x_3+=vx_3;
        y_1+=vy_1;
        y_2+=vx_2;
        y_3+=vx_3;






        //collision mechanics from boundary
        // multiply by -1 reverses pos of the vertex
        if (x_1 < 0 || x_1 >= width) vx_1 *= -1;
        if (x_2 < 0 || x_2 >= width) vx_2 *= -1;
        if (x_3 < 0 || x_3 >= width) vx_3 *= -1;
        if (y_1 < 0 || y_1 >= height) vy_1 *= -1;
        if (y_2 < 0 || y_2 >= height) vy_2 *= -1;
        if (y_3 < 0 || y_3 >= height) vy_3 *= -1;




        //62.5 frames per sec , changing time variable so it can affect color
        t+=0.016;


        //render buffer swapping between 2 windows
        glfwSwapBuffers(window);
        //Process window and input events
        glfwPollEvents();
        
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;

}