/*
 * Copyright (C) 2017 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     rekols <rekols@foxmail.com>
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

#include "basickeypadtab.h"

#include <QTimer>
#include <DPalette>
#include <DImageButton>

#include "dthememanager.h"

const int KEYPAD_HEIGHT = 483; //键盘界面高度
const int KEYPAD_SPACING = 8; //键盘按键间距,按钮比ui大2pix,此处小2pix
const int LEFT_MARGIN = 19; //键盘左边距
const int RIGHT_MARGIN = 19; //键盘右边距
const int BOTTOM_MARGIN = 20; //键盘下边距
const QSize STANDARD_TEXTBTNSIZE = QSize(351, 87); //标准模式按钮大小，为画边框比ui大2pix

const BasicKeypadTab::KeyDescription BasicKeypadTab::keyDescriptions[] = {
//    {"MC", Key_MC, 1, 0, 1, 2},       {"MR", Key_MR, 1, 2, 1, 2},
//    {"M+", Key_Mplus, 1, 4, 1, 2},    {"M-", Key_Mminus, 1, 6, 1, 2},
//    {"MS", Key_MS, 1, 8, 1, 2},       {"M^", Key_Mlist, 1, 10, 1, 2},

    {"C", Key_Clear, 1, 0, 1, 3},     {"%", Key_Percent, 1, 3, 1, 3},
    {"", Key_Backspace, 1, 6, 1, 3},  {"", Key_Div, 1, 9, 1, 3},

    {"7", Key_7, 2, 0, 1, 3},         {"8", Key_8, 2, 3, 1, 3},
    {"9", Key_9, 2, 6, 1, 3},         {"", Key_Mult, 2, 9, 1, 3},

    {"4", Key_4, 3, 0, 1, 3},         {"5", Key_5, 3, 3, 1, 3},
    {"6", Key_6, 3, 6, 1, 3},         {"", Key_Min, 3, 9, 1, 3},

    {"1", Key_1, 4, 0, 1, 3},         {"2", Key_2, 4, 3, 1, 3},
    {"3", Key_3, 4, 6, 1, 3},         {"", Key_Plus, 4, 9, 1, 3},

    {"0", Key_0, 5, 0, 1, 3},         {".", Key_Point, 5, 3, 1, 3},
    {"()", Key_Brackets, 5, 6, 1, 3}, {"=", Key_Equals, 5, 9, 1, 3}
};

/**
 * @brief 初始化并设置iconbutton
 */
//static DPushButton *createSpecialKeyButton(BasicKeypadTab::Buttons key)
//{
//    IconButton *button = new IconButton;

//    QString path;
//    if (DGuiApplicationHelper::instance()->themeType() == 2)
//        path = QString(":/assets/images/%1/").arg("dark");
//    else
//        path = QString(":/assets/images/%1/").arg("light");

//    if (key == BasicKeypadTab::Key_Div) {
//        button->setIconUrl(path + "divide_normal.svg", path + "divide_hover.svg", path + "divide_press.svg");
//    } else if (key == BasicKeypadTab::Key_Mult) {
//        button->setIconUrl(path + "x_normal.svg", path + "x_hover.svg", path + "x_press.svg");
//    } else if (key == BasicKeypadTab::Key_Min) {
//        button->setIconUrl(path + "-_normal.svg", path + "-_hover.svg", path + "-_press.svg");
//    } else if (key == BasicKeypadTab::Key_Plus) {
//        button->setIconUrl(path + "+_normal.svg", path + "+_hover.svg", path + "+_press.svg");
//    } else if (key == BasicKeypadTab::Key_Backspace) {
//        button->setIconUrl(path + "clear_normal.svg", path + "clear_hover.svg", path + "clear_press.svg");
//    }
//    return button;
//}

BasicKeypadTab::BasicKeypadTab(QWidget *parent)
    : DWidget(parent),
      m_layout(new QGridLayout(this)),
      m_mapper(new QSignalMapper(this))
{
    this->setFixedHeight(KEYPAD_HEIGHT);
    m_layout->setMargin(0);
    m_layout->setSpacing(KEYPAD_SPACING);
    m_layout->setContentsMargins(0, 0, 0, 0);
//    setFocusPolicy(Qt::StrongFocus);

    installEventFilter(this);

    initButtons();
    initUI();

    connect(m_mapper, SIGNAL(mapped(int)), SIGNAL(buttonPressed(int)));
}

BasicKeypadTab::~BasicKeypadTab()
{
}

void BasicKeypadTab::mouseMoveEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
}

/**
 * @brief 根据枚举值返回相应button
 * @param key 按钮名
 */
DPushButton *BasicKeypadTab::button(Buttons key)
{
    return m_keys.value(key).first;
}

DPushButton *BasicKeypadTab::button(int key)
{
    return m_keys.value(Buttons(key)).first;
}

/**
 * @brief 按钮点击动画效果
 */
void BasicKeypadTab::animate(Buttons key, bool isspace)
{
    if (button(key)->text().isEmpty()) {
        IconButtonTab *btn = static_cast<IconButtonTab *>(button(key));
        btn->animate(isspace);
    } else {
        if (button(key)->text() == "=") {
            EqualButtonTab *btn = dynamic_cast<EqualButtonTab *>(button(key));
            btn->animate(isspace);
        } else {
            TextButtonTab *btn = static_cast<TextButtonTab *>(button(key));
            btn->animate(isspace);
        }
    }
}

bool BasicKeypadTab::buttonHasFocus()
{
    QHashIterator<Buttons, QPair<DPushButton *, const KeyDescription *>> i(m_keys);
    while (i.hasNext()) {
        i.next();
        if (i.value().first->hasFocus()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief 初始化button
 */
void BasicKeypadTab::initButtons()
{
    const int count = sizeof(keyDescriptions) / sizeof(keyDescriptions[0]);
    for (int i = 0; i < count; ++i) {
        const KeyDescription *desc = keyDescriptions + i;
        DPushButton *button;

        if (desc->text.isEmpty()) {
            button = new IconButtonTab(this);
//            button = createSpecialKeyButton(desc->button);
//            button->setParent(this);
        } else {
            if (desc->text == "=") {
                button = new EqualButtonTab(desc->text, this);
                connect(static_cast<EqualButtonTab *>(button), &EqualButtonTab::focus, this, &BasicKeypadTab::getFocus); //获取上下左右键
                connect(static_cast<EqualButtonTab *>(button), &EqualButtonTab::space, this, [ = ]() {
                    Buttons spacekey = Key_Equals;
                    emit buttonPressedbySpace(spacekey);
                });
            } else {
                button = new TextButtonTab(desc->text, false, this);
            }
        }

        button->setFixedSize(STANDARD_TEXTBTNSIZE);
        m_layout->addWidget(button, desc->row, desc->column, desc->rowcount, desc->columncount,
                            Qt::AlignHCenter | Qt::AlignVCenter);
        const QPair<DPushButton *, const KeyDescription *> hashValue(button, desc);
        m_keys.insert(desc->button, hashValue); //key为枚举值，value.first为DPushButton *, value.second为const KeyDescription *

        connect(static_cast<TextButtonTab *>(button), &TextButtonTab::focus, this, &BasicKeypadTab::getFocus); //获取上下左右键
        connect(static_cast<TextButtonTab *>(button), &TextButtonTab::updateInterface, [ = ] {update();}); //点击及焦点移除时update
        connect(static_cast<TextButtonTab *>(button), &TextButtonTab::space, this, [ = ]() {
            Buttons spacekey = m_keys.key(hashValue);
            emit buttonPressedbySpace(spacekey);
        });
        connect(button, &DPushButton::clicked, m_mapper, static_cast<void (QSignalMapper::*)()>(&QSignalMapper::map));
        connect(static_cast<TextButtonTab *>(button), &TextButtonTab::moveLeft, this, &BasicKeypadTab::moveLeft);
        connect(static_cast<TextButtonTab *>(button), &TextButtonTab::moveRight, this, &BasicKeypadTab::moveRight);
        m_mapper->setMapping(button, desc->button); //多个按钮绑定到一个mapper上
    }
}

void BasicKeypadTab::initUI()
{
    button(Key_Div)->setObjectName("SymbolButton");
    button(Key_Mult)->setObjectName("SymbolButton");
    button(Key_Min)->setObjectName("SymbolButton");
    button(Key_Plus)->setObjectName("SymbolButton");

    this->setContentsMargins(LEFT_MARGIN, 0, RIGHT_MARGIN, BOTTOM_MARGIN);
}

/**
 * @brief 切换相应主题切图
 */
void BasicKeypadTab::buttonThemeChanged(int type)
{
    QString path;
    if (type == 2)
        path = QString(":/assets/images/%1/").arg("dark");
    else
        path = QString(":/assets/images/%1/").arg("light");

    IconButtonTab *btn = static_cast<IconButtonTab *>(button(Key_Div));
    btn->setIconUrl(path + "divide_normal.svg", path + "divide_hover.svg", path + "divide_press.svg");
    btn = static_cast<IconButtonTab *>(button(Key_Mult));
    btn->setIconUrl(path + "x_normal.svg", path + "x_hover.svg", path + "x_press.svg");
    btn = static_cast<IconButtonTab *>(button(Key_Min));
    btn->setIconUrl(path + "-_normal.svg", path + "-_hover.svg", path + "-_press.svg");
    btn = static_cast<IconButtonTab *>(button(Key_Plus));
    btn->setIconUrl(path + "+_normal.svg", path + "+_hover.svg", path + "+_press.svg");
    btn = static_cast<IconButtonTab *>(button(Key_Backspace));
    btn->setIconUrl(path + "clear_normal.svg", path + "clear_hover.svg", path + "clear_press.svg", 1);
}

/**
 * @brief 获取button上下左右键信号setfocus
 * @param direction 0-上　1-下　2-左　3-右
 */
void BasicKeypadTab::getFocus(int direction)
{
    QHashIterator<Buttons, QPair<DPushButton *, const KeyDescription *>> i(m_keys);
    while (i.hasNext()) {
        i.next();
        if (i.value().first->hasFocus()) {
            break; //获取焦点按钮
        }
    }
    switch (direction) {
    case 0:
        if (i.key() / 4 > 0)
            button(static_cast<Buttons>(i.key() - 4))->setFocus(); //根据上下左右信号重置焦点
        break;
    case 1:
        if (i.key() / 4 < 4)
            button(static_cast<Buttons>(i.key() + 4))->setFocus();
        break;
    case 2:
        if (i.key() % 4 > 0)
            button(static_cast<Buttons>(i.key() - 1))->setFocus();
        break;
    case 3:
        if (i.key() % 4 < 3)
            button(static_cast<Buttons>(i.key() + 1))->setFocus();
        break;
    default:
        break;
    }
}
