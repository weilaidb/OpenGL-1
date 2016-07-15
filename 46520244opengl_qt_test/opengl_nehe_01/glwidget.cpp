#include "glwidget.h"
#include "ui_glwidget.h"

#include <QtGui>
#include <QtCore>
#include <QtOpenGL>

GLWidget::GLWidget(QGLWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::GLWidget)
{
  //  setCaption("The Opengl for Qt Framework");
    ui->setupUi(this);
    fullscreen = false;

}

//���Ƕ��麯������������д�ú���
void GLWidget::initializeGL()
{
    setGeometry(300, 150, 640, 480);//���ô��ڳ�ʼλ�úʹ�С
    glShadeModel(GL_FLAT);//������Ӱƽ��ģʽ
    glClearColor(0.5, 1.0, 0.2, 0);//�ı䴰�ڵı�����ɫ������������ò�����ú�û��ʲôЧ��
    glClearDepth(1.0);//������Ȼ���
    glEnable(GL_DEPTH_TEST);//������Ȳ���
    glDepthFunc(GL_LEQUAL);//������Ȳ�������
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//����͸��У��
}

void GLWidget::paintGL()
{
    //glClear()������������Ƕ�initializeGL()���������õ���ɫ�ͻ�����ȵ�������
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//���õ�ǰ��ģ�͹۲���󣿲��Ǻ���⣡
}

//�ó���������opengl����͸��ͼ�����������ٱ�ִ��һ��(��������ʱ).
void GLWidget::resizeGL(int width, int height)
{
    if(0 == height)
        height = 1;//��ֹһ����Ϊ0
    glViewport(0, 0, (GLint)width, (GLint)height);//���õ�ǰ�ӿڣ����������ô��ڵģ�ֻ���������ﱻQt����װ����
    glMatrixMode(GL_PROJECTION);//ѡ��ͶӰ����
    glLoadIdentity();//����ѡ��õ�ͶӰ����
   // gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0);//����͸��ͶӰ����
    //glMatirxMode(GL_MODELVIEW);//����2���������ֵĽ���һ��

    glLoadIdentity();


}
void GLWidget::keyPressEvent(QKeyEvent *e)
{
    switch(e->key())
    {
        //F1��Ϊȫ������ͨ����ʾ�л���
        case Qt::Key_F1:
            fullscreen = !fullscreen;
            if(fullscreen)
                showFullScreen();
            else
            {
                setGeometry(300, 150, 640, 480);
                showNormal();
            }
            updateGL();
            break;
        //EseΪ�˳������
        case Qt::Key_Escape:
            close();
    }
}

GLWidget::~GLWidget()
{
    delete ui;
}
