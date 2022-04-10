#include "TXLib.h"

//{----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует тело кота заданного размера
//!
//!@note <i>Неплохое тело породистого рыжего кота</i>
//!
//! <table border = 0>
//! <tr><td> @image html cat_body.png </td>
//! <td>
//!@param x           x - координата начальной точки (точка соединения головы и тела кота)
//!@param y           y - координата начальной точки (точка соединения головы и тела кота)
//!@param size        size - размер тела кота
//!@param distFoot    distFoot - расстояние между ногами кота
//!@param distTail    distTail - растояние, на которое двигается хвост
//!@param hLeftFoot   hLeftFoot - расстояние, на которое поднимается правая лапка кота
//!@param hRightFoot  hRightFoot - расстояние, на которое поднимается левая лапка кота
//!@param rLeftFoot   rLeftFoot - радиус левой лапки кота
//!@param rRightFoot  rRightFoot - радиус правой лапки кота
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par  Пример использования
//!@code
//!         CatBody (600, 400, 2, 20, 70, -5, -5, 5, 5);
//!@endcode
//}----------------------------------------------------------------------------

void CatBody (double x, double y, double size,
              double distFoot,
              double distTail,
              double hLeftFoot, double hRightFoot,
              double rLeftFoot, double rRightFoot);  // Всего 9 параметров

//-----------------------------------------------------------------------------
void CatBody (double x, double y, double size,
              double distFoot,
              double distTail,
              double hLeftFoot, double hRightFoot,
              double rLeftFoot, double rRightFoot)
    {
    //---Брюшко---
    txSetFillColor (RGB(217, 113, 28));
    POINT body[3] = {{ROUND(x),           ROUND(y)          },
                     {ROUND(x - 40*size), ROUND(y + 70*size)},
                     {ROUND(x + 40*size), ROUND(y + 70*size)}};
    txPolygon (body, 3);

    //---Лапки---
    //------Левая лапка------
    txSetFillColor (RGB(206, 107, 74));
    txCircle (x - distFoot, y + 70*size + hLeftFoot, rLeftFoot*size);

    //------Правая лапка------
    txSetFillColor (RGB(206, 107, 74));
    txCircle (x + distFoot, y + 70*size + hRightFoot, rRightFoot*size);

    //---Хвостик---
    txLine (x + 40*size, y + 70*size, x + distTail*size, y);

    }


//{----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует голову кота заданного размера
//!
//!@note <i>Неплохая голова породистого рыжего кота</i>
//!
//! <table border = 0>
//! <tr><td> @image html cat_head.png </td>
//! <td>
//!@param x           x - координата начальной точки (точка соединения головы и тела кота)
//!@param y           y - координата начальной точки (точка соединения головы и тела кота)
//!@param widthline   widthline - толщина линий фигур
//!@param size        size - размер головы кота
//!@param distEars    distEars - расстояние между кончиков ушей кота
//!@param redHead     redHead - номер цвета лежащий в цифровой модели RGB
//!@param greenHat    greenHat - номер цвета лежащий в цифровой модели RGB
//!@param blueHead    blueHead - номер цвета лежащий в цифровой модели RGB
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par  Пример использования
//!@code
//!         CatHead (600, 400, 2, 2, 30, redHat, greenHat, blueHat);  //8
//!         redHat += 3*n;
//!         greenHat += 2*n;
//!         blueHat += 1*n;
//!@endcode
//}----------------------------------------------------------------------------

void CatHead (double x, double y, int widthline, double size,
              double distEars,
              int redHat, int greenHat, int blueHat);  // Всего 8 параметров

//-----------------------------------------------------------------------------
void CatHead (double x, double y, int widthline, double size,
              double distEars,
              int redHat, int greenHat, int blueHat)
    {
    //---Голова---
    txSetColor ((TX_BLACK), widthline);
    txSetFillColor (RGB(217, 113, 28));
    txCircle (x, y - 20*size, 20*size);

    //---Носик---
    txSetFillColor ((TX_BLACK));
    POINT nose[3] = {{ROUND(x),          ROUND(y - 10*size)},
                     {ROUND(x - 3*size), ROUND(y - 15*size)},
                     {ROUND(x + 3*size), ROUND(y - 15*size)}};
    txPolygon (nose, 3);

    //---Усы---
    txLine (x, y - 10*size, x + 20*size, y - 20*size);
    txLine (x, y - 10*size, x + 20*size, y - 10*size);
    txLine (x, y - 10*size, x - 20*size, y - 20*size);
    txLine (x, y - 10*size, x - 20*size, y - 10*size);

    //---Ушки---
    //------Левое ушко------
    txSetFillColor (RGB(217, 113, 28));
    POINT leftEar[3] = {{ROUND(x - 18*size),       ROUND(y - 28*size)},
                        {ROUND(x - distEars*size), ROUND(y - 50*size)},
                        {ROUND(x - 10*size),       ROUND(y - 38*size)}};
    txPolygon (leftEar, 3);

    //------Правое ушко------
    txSetFillColor (RGB(217, 113, 28));
    POINT rightEar[3] = {{ROUND(x + 18*size),       ROUND(y - 28*size)},
                         {ROUND(x + distEars*size), ROUND(y - 50*size)},
                         {ROUND(x + 10*size),       ROUND(y - 38*size)}};
    txPolygon (rightEar, 3);

    //---Глазки---
    txSetFillColor (TX_BLACK);
    txCircle (x - 6*size, y - 22*size, 2*size);
    txCircle (x + 6*size, y - 22*size, 2*size);

    //---Ротик---
    txLine (x, y - 10*size, x - 3*size, y - 10);
    txLine (x, y - 10*size, x + 3*size, y - 10);

    //---Колпачок---
    txSetFillColor (RGB(redHat, greenHat, blueHat));
    POINT hatForCat[3] = {{ROUND(x - 10*size), ROUND(y - 39*size)},
                          {ROUND(x),           ROUND(y - 70*size)},
                          {ROUND(x + 10*size), ROUND(y - 39*size)}};
    txPolygon (hatForCat, 3);
    }


//{----------------------------------------------------------------------------
//!@ingroup Persons
//!
//! Рисует перевернутую голову кота заданного размера
//!
//!@note <i>Неплохая перевернутая голова породистого рыжего кота</i>
//!
//! <table border = 0>
//! <tr><td> @image html cat_reversedhead.png </td>
//! <td>
//!@param x           x - координата начальной точки (точка соединения головы и тела кота)
//!@param y           y - координата начальной точки (точка соединения головы и тела кота)
//!@param widthline   widthline - толщина линий фигур
//!@param size        size - размер головы кота
//!@param distEars    distEars - расстояние между кончиков ушей кота
//!@param redHead     redHead - номер цвета лежащий в цифровой модели RGB
//!@param greenHat    greenHat - номер цвета лежащий в цифровой модели RGB
//!@param blueHead    blueHead - номер цвета лежащий в цифровой модели RGB
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par  Пример использования
//!@code
//!         CatReversedHead (600, 400, 2, 2, 30, redHat, greenHat, blueHat);
//!         redHat += 3*n;
//!         greenHat += 2*n;
//!         blueHat += 1*n;
//!@endcode
//}----------------------------------------------------------------------------

void CatReversedHead (double x, double y, int widthline, double size,
                      double distEars,
                      int redHat, int greenHat, int blueHat);  // Всего 8 параметров

//-----------------------------------------------------------------------------
void CatReversedHead (double x, double y, int widthline, double size,
                      double distEars,
                      int redHat, int greenHat, int blueHat)
    {
    //---Голова---
    txSetColor ((TX_BLACK), widthline);
    txSetFillColor (RGB(217, 113, 28));
    txCircle (x, y - 20*size, 20*size);

    //---Носик---
    txSetFillColor ((TX_BLACK));
    POINT nose[3] = {{ROUND(x),          ROUND(y - 30*size)},
                     {ROUND(x - 3*size), ROUND(y - 25*size)},
                     {ROUND(x + 3*size), ROUND(y - 25*size)}};
    txPolygon (nose, 3);

    //---Усы---
    txLine (x, y - 30*size, x + 20*size, y - 20*size);
    txLine (x, y - 30*size, x + 20*size, y - 30*size);
    txLine (x, y - 30*size, x - 20*size, y - 20*size);
    txLine (x, y - 30*size, x - 20*size, y - 30*size);

    //---Ушки---
    //------Левое ушко------
    txSetFillColor (RGB(217, 113, 28));
    POINT leftEar[3] = {{ROUND(x - 18*size),       ROUND(y - 12*size)},
                        {ROUND(x - distEars*size), ROUND(y + 10*size)},
                        {ROUND(x - 10*size),       ROUND(y - 2*size)}};
    txPolygon (leftEar, 3);

    //------Правое ушко------
    txSetFillColor (RGB(217, 113, 28));
    POINT rightEar[3] = {{ROUND(x + 18*size),       ROUND(y - 12*size)},
                         {ROUND(x + distEars*size), ROUND(y + 10*size)},
                         {ROUND(x + 10*size),       ROUND(y - 2*size)}};
    txPolygon (rightEar, 3);

    //---Глазки---
    txSetFillColor (TX_BLACK);
    txCircle (x - 6*size, y - 18*size, 2*size);
    txCircle (x + 6*size, y - 18*size, 2*size);

    //---Ротик---
    txLine (x, y - 30*size, x - 3*size, y - 30);
    txLine (x, y - 30*size, x + 3*size, y - 30);

    //---Колпачок---
    txSetFillColor (RGB(redHat, greenHat, blueHat));
    POINT hatForCat[3] = {{ROUND(x - 10*size), ROUND(y - 1*size)},
                          {ROUND(x),           ROUND(y + 30*size)},
                          {ROUND(x + 10*size), ROUND(y - 1*size)}};
    txPolygon (hatForCat, 3);
    }


//{----------------------------------------------------------------------------
//!@ingroup Things
//!
//! Рисует музыкальную колонку
//!
//!@note <i>Хорошая музыкальная колонка</i>
//!
//! <table border = 0>
//! <tr><td> @image html voicebox.png </td>
//! <td>
//!@param x           x - координата начальной точки
//!@param y           y - координата начальной точки
//!@param size        size - размер колонки
//!@param widthline   widthline - толщина линий фигур
//!@param rCircle     rCircle - радиус динамика колонки
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par  Пример использования
//!@code
//!        VoiceBox (800, 500, 2, 2, 15);
//!@endcode
//}----------------------------------------------------------------------------

void VoiceBox (double x, double y, double size, double widthline,
               double rCircle);  // Всего 5 параметров

//-----------------------------------------------------------------------------
void VoiceBox (double x, double y, double size, double widthline,
               double rCircle)
    {
    //---Колонка---
    txSetFillColor (TX_BLACK);
    txRectangle (x, y, x + 40*size, y - 80*size);
    //------Динамики------
    txSetFillColor (TX_GRAY);
    txCircle (x + 20*size, y - 60*size, rCircle*size);
    txCircle (x + 20*size, y - 20*size, rCircle*size);
    txSetColor (TX_BLACK, widthline);
    txCircle (x + 20*size, y - 20*size, rCircle*size/2);
    txCircle (x + 20*size, y - 60*size, rCircle*size/2);
    }


//{----------------------------------------------------------------------------
//!@ingroup Things
//!
//! Рисует фон с зеленой лужайкой, голубым небом и желтым солнышком
//!
//!@note <i>Вполне приятный задний фон</i>
//!
//! <table border = 0>
//! <tr><td> @image html background.png </td>
//! </tr>
//! </table>
//!
//!
//!@par  Пример использования
//!@code
//!        Background ();
//!@endcode
//}----------------------------------------------------------------------------

void Background ();  // Всего 0 параметров

//-----------------------------------------------------------------------------
void Background ()
    {
    //---Трава---
    txSetFillColor (RGB(127, 235, 77));
    txRectangle (0, 450, 1200, 800);
    //---Небо---
    txSetFillColor (RGB(168, 216, 255));
    txRectangle (0, 455, 1200, 0);
    //---Солнышко---
    txSetFillColor (TX_YELLOW);
    txCircle (1150, 75, 120);
    }


//{----------------------------------------------------------------------------
//!@ingroup Things
//!
//! Рисует белое облачко
//!
//!@note <i>Пушистое белое облачко</i>
//!
//! <table border = 0>
//! <tr><td> @image html cloud.png </td>
//! <td>
//!@param x           x - координата начальной точки
//!@param y           y - координата начальной точки
//!@param size        size - размер колонки
//!@param widthline   widthline - толщина линий фигур
//!@param rCircle     rCircle - радиус кругов на краю прямоугольника(не рекомендуется задавать маленькие значения!)
//! </td>
//! </tr>
//! </table>
//!
//!
//!@par  Пример использования
//!@code
//!        Cloud (400, 55, 2, 50);
//!@endcode
//}----------------------------------------------------------------------------

void Cloud (double x, double y, int widthline,
            double rCircle); // Всего 4 параметра

//-----------------------------------------------------------------------------
void Cloud (double x, double y, int widthline,
            double rCircle)
    {
    txSetColor (TX_WHITE, widthline);
    txSetFillColor (TX_WHITE);
    txRectangle (x, y, x + 100, y + 50);
    txCircle (x, y, rCircle);
    txCircle (x + 35, y, rCircle - 5);
    txCircle (x + 50, y, rCircle + 4);
    txCircle (x + 80, y, rCircle - 2);
    txCircle (x, y + 30, rCircle -5);
    txCircle (x + 30, y + 30, rCircle - 1);
    txCircle (x + 60, y + 30, rCircle + 3);
    txCircle (x + 90, y + 30, rCircle);
    txSetColor (TX_BLACK, widthline);
    }


//{----------------------------------------------------------------------------
//!@ingroup Things
//!
//! Рисует 4 белых облачка
//!
//!@note <i>4 пушистых белых облачка</i>
//!
//! <table border = 0>
//! <tr><td> @image html clouds.png </td>
//! </tr>
//! </table>
//!
//!
//!@par  Пример использования
//!@code
//!        Clouds ();
//!@endcode
//}----------------------------------------------------------------------------

void Clouds ();  // Всего 0 параметров

//-----------------------------------------------------------------------------
void Clouds ()
    {
    Cloud (200, 100, 2, 30);
    Cloud (400, 55, 2, 50);
    Cloud (650, 150, 2, 35);
    Cloud (900, 200, 2, 40);
    }
