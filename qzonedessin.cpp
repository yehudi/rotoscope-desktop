#include "qzonedessin.h"
#include <iostream>

QZoneDessin::QZoneDessin(QWidget * parent)
{
    QWidget(parent,0);
    m_image = NULL;
    m_actif = 0;
    m_position = NULL;

}


void QZoneDessin::resizeEvent(QResizeEvent * e)
{
    if (m_image == NULL)
    {
        m_image = new QImage(e->size(),QImage::Format_Mono);
        QPainter p(m_image);
        p.fillRect(0,0,1500,1200,Qt::white);
    }
    else
    {
        QImage * image = new QImage(e->size(),QImage::Format_Mono);
        //copie de l'image
        QPainter p(image);
        p.fillRect(0,0,1500,1200,Qt::white);
        p.drawImage(0,0,*m_image);
        delete m_image;
        m_image = new QImage(*image);
    }
}

void QZoneDessin::paintEvent(QPaintEvent * e)
{
    QPainter  p(this);
    p.drawImage(0,0,*m_image);
}

void QZoneDessin::mousePressEvent(QMouseEvent *event)
{
    m_position = new QPoint(event->pos() );
    m_actif = 1;
    //std::cout << "press " << std::endl;
}

void QZoneDessin::mouseMoveEvent(QMouseEvent *event)
{
    if (m_actif==1)
    {
        emit draw();
        //std::cout << "actif" << std::endl;
        QPainter paint(m_image);
        QPoint * position = new QPoint(event->pos());
        QLine * l = new QLine(*m_position,*position);
        paint.drawLine(*l);
        delete m_position;
        m_position = new QPoint(*position);
        delete position;
        delete l;
    this->update();
    }
}

void QZoneDessin::mouseReleaseEvent(QMouseEvent *event)
{
    //std::cout << "relache" << std::endl;
    delete m_position;
    m_actif = 0;
}

void QZoneDessin::clearDessin()
{
    QSize s(m_image->size());
    delete m_image;
    m_image = new QImage(s,QImage::Format_Mono);
    QPainter p(m_image);
    p.fillRect(0,0,m_image->height(),m_image->height(),Qt::white);
    this->update();
}

