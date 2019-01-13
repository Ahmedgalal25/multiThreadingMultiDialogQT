/********************************************************************************
** Form generated from reading UI file 'cannydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANNYDIALOG_H
#define UI_CANNYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CannyDialog
{
public:
    QLabel *cannyLabel;
    QLabel *label_threadId;

    void setupUi(QDialog *CannyDialog)
    {
        if (CannyDialog->objectName().isEmpty())
            CannyDialog->setObjectName(QStringLiteral("CannyDialog"));
        CannyDialog->resize(720, 622);
        cannyLabel = new QLabel(CannyDialog);
        cannyLabel->setObjectName(QStringLiteral("cannyLabel"));
        cannyLabel->setGeometry(QRect(40, 30, 561, 441));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cannyLabel->sizePolicy().hasHeightForWidth());
        cannyLabel->setSizePolicy(sizePolicy);
        label_threadId = new QLabel(CannyDialog);
        label_threadId->setObjectName(QStringLiteral("label_threadId"));
        label_threadId->setGeometry(QRect(140, 530, 301, 41));

        retranslateUi(CannyDialog);

        QMetaObject::connectSlotsByName(CannyDialog);
    } // setupUi

    void retranslateUi(QDialog *CannyDialog)
    {
        CannyDialog->setWindowTitle(QApplication::translate("CannyDialog", "Dialog", nullptr));
        cannyLabel->setText(QString());
        label_threadId->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CannyDialog: public Ui_CannyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANNYDIALOG_H
