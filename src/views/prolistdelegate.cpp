#include "prolistdelegate.h"

ProListDelegate::ProListDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

ProListDelegate::~ProListDelegate()
{

}

void ProListDelegate::setThemeType(int type)
{
    m_themeType = type;
}

void ProListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    const QString expression = index.data(ProListModel::ExpressionRole).toString();
    ProListView *listview = qobject_cast<ProListView *>(option.styleObject);
    QRect selectrect(option.rect.x(), option.rect.y() + 3, 3, option.rect.height() - 6);  //被选中行选中标记
    QRect hoverrect(option.rect.x(), option.rect.y() + 1, 427, option.rect.height() - 2);  //hover背景色
    QRect textrect(option.rect.x() + 80, option.rect.y(), 268, 24);  //textrect
    QRect systemrect(option.rect.x() + 10, option.rect.y(), 24, 24);  //进制字体框

    QColor hoverbackground, fontColor, systemfontColor;
    if (m_themeType == 1) {
        hoverbackground = QColor(0, 0, 0);
        hoverbackground.setAlphaF(0.03);
        fontColor = QColor("#838483");
        systemfontColor = QColor("#303030");
    } else {
        hoverbackground = QColor(255, 255, 255);
        hoverbackground.setAlphaF(0.05);
        fontColor = QColor("#B4B4B4");
        systemfontColor = QColor("#C0C6D4");
    }

    QFont font; //结果字体
    font.setPixelSize(14);
//    font.setLetterSpacing(QFont::PercentageSpacing, 0); //字间距0，未发现有效果
    QFont systemfont; //进制字体
    systemfont.setPixelSize(12);

    //选中框绘制
    if (index == listview->currentIndex()) {
        painter->setPen(Qt::NoPen);
        painter->setBrush(QBrush(Dtk::Gui::DGuiApplicationHelper::instance()->applicationPalette().highlight().color()));
        painter->drawRect(selectrect);
    }

    //进制字体绘制
    painter->setFont(systemfont);
    if (index == listview->currentIndex())
        painter->setPen(Dtk::Gui::DGuiApplicationHelper::instance()->applicationPalette().highlight().color());
    else
        painter->setPen(systemfontColor);
    switch (index.row()) {
    case 0:
        painter->drawText(systemrect, "HEX", Qt::AlignHCenter | Qt::AlignVCenter);
        break;
    case 1:
        painter->drawText(systemrect, "DEC", Qt::AlignHCenter | Qt::AlignVCenter);
        break;
    case 2:
        painter->drawText(systemrect, "OCT", Qt::AlignHCenter | Qt::AlignVCenter);
        break;
    case 3:
        painter->drawText(systemrect, "BIN", Qt::AlignHCenter | Qt::AlignVCenter);
        break;

    }

    //悬浮背景绘制
    if (option.state & QStyle::State_MouseOver) {
        painter->setBrush(hoverbackground);
        painter->setPen(Qt::NoPen);
        painter->drawRect(hoverrect);
    }

    //结果字体绘制
    painter->setFont(font);
    painter->setPen(fontColor);
    if (index.row() == 3) {
        if (expression.size() > 39) {
            //第一行
            painter->drawText(QRect(option.rect.x() + 80, option.rect.y(), 280, 14),
                              expression.mid(0, 39), Qt::AlignLeft | Qt::AlignVCenter);
            //第二行
            painter->drawText(QRect(option.rect.x() + 80, option.rect.y() + 14, 280, 14),
                              expression.mid(40, -1), Qt::AlignLeft | Qt::AlignVCenter);
        } else {
            painter->drawText(QRect(option.rect.x() + 80, option.rect.y(), 268, 28), expression, Qt::AlignLeft | Qt::AlignVCenter);
        }
    } else
        painter->drawText(textrect, expression, Qt::AlignLeft | Qt::AlignVCenter);
}

QSize ProListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    if (index.row() == 3)
        return QSize(427, 28);
    else
        return QSize(427, 24);
}

bool ProListDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    Q_UNUSED(event);
    Q_UNUSED(model);
    Q_UNUSED(option);
    emit obtainingHistorical(index);
    return true;
}

void ProListDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}