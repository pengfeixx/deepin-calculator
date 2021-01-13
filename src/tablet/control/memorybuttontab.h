/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     xiajing <xiajing@uniontech.com>
*
* Maintainer: jingzhou <jingzhou@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MemoryButtonTab_H
#define MemoryButtonTab_H

#include <QDebug>
#include <QGraphicsDropShadowEffect>
#include <QHelpEvent>
#include <QToolTip>
#include <DPalette>
#include <DPushButton>

#include "textbuttontab.h"

DWIDGET_USE_NAMESPACE
DGUI_USE_NAMESPACE

/**
 * @brief 标准模式内存按键
 */
class MemoryButtonTab : public TextButtonTab
{
    Q_OBJECT

public:
    MemoryButtonTab(const QString &text = QString(), bool listwidgetbtn = false, QWidget *parent = nullptr); //listwidgetbtn-是否是内存界面中的按钮
    ~MemoryButtonTab();

    void init();
    // void showShadow();
    // void hideShadow();
    void animate(bool isspace = false, int msec = 100);
    void setbtnlight(bool light);
    void showtips();
public slots:
    void setbuttongray(bool memorywidgetshow);
    void updateWhenBtnDisable();

signals:
    void moveLeft();
    void moveRight();
    void updateInterface();

public:
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void paintEvent(QPaintEvent *e);
    void focusOutEvent(QFocusEvent *);

private:
    QGraphicsDropShadowEffect *m_effect;

    DPalette m_palette;
    bool m_isHover;
    bool m_isPress;
    bool m_isgray; //按键不可用置灰
    QFont m_font;
    bool m_widgetbtn; //内存列表按键
    bool m_isallgray; //内存区显示置灰
    bool m_isacting = false; //规避鼠标在button内release时出现foucus状态的框
};

#endif  // MemoryButtonTab_H