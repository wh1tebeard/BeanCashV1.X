#include "beancontroltreewidget.h"
#include "beancontroldialog.h"

BeanControlTreeWidget::BeanControlTreeWidget(QWidget *parent) :
    QTreeWidget(parent)
{

}

void BeanControlTreeWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) // press spacebar -> select checkbox
    {
        event->ignore();
        int COLUMN_CHECKBOX = 0;
        this->currentItem()->setCheckState(COLUMN_CHECKBOX, ((this->currentItem()->checkState(COLUMN_CHECKBOX) == Qt::Checked) ? Qt::Unchecked : Qt::Checked));
    }
    else if (event->key() == Qt::Key_Escape) // press esc -> close dialog
    {
        event->ignore();
        BeanControlDialog *beanControlDialog = (BeanControlDialog*)this->parentWidget();
        beanControlDialog->done(QDialog::Accepted);
    }
    else
    {
        this->QTreeWidget::keyPressEvent(event);
    }
}