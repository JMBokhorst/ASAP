/********************************************************************************
** Form generated from reading UI file 'WorklistWindowLayout.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKLISTWINDOWLAYOUT_H
#define UI_WORKLISTWINDOWLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorklistWindowLayout
{
public:
    QAction *action_open_file;
    QAction *action_open_folder;
    QAction *action_open_external;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_studies;
    QTableView *view_studies;
    QLabel *label_patients;
    QLabel *label_worklists;
    QTreeView *view_worklists;
    QTableView *view_patients;
    QListView *view_images;
    QLabel *label_images;
    QMenuBar *menuBar;
    QMenu *menuStart;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *WorklistWindowLayout)
    {
        if (WorklistWindowLayout->objectName().isEmpty())
            WorklistWindowLayout->setObjectName(QStringLiteral("WorklistWindowLayout"));
        WorklistWindowLayout->resize(1113, 850);
        action_open_file = new QAction(WorklistWindowLayout);
        action_open_file->setObjectName(QStringLiteral("action_open_file"));
        action_open_folder = new QAction(WorklistWindowLayout);
        action_open_folder->setObjectName(QStringLiteral("action_open_folder"));
        action_open_external = new QAction(WorklistWindowLayout);
        action_open_external->setObjectName(QStringLiteral("action_open_external"));
        centralWidget = new QWidget(WorklistWindowLayout);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_studies = new QLabel(centralWidget);
        label_studies->setObjectName(QStringLiteral("label_studies"));

        gridLayout->addWidget(label_studies, 2, 1, 1, 1);

        view_studies = new QTableView(centralWidget);
        view_studies->setObjectName(QStringLiteral("view_studies"));
        view_studies->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        view_studies->setAlternatingRowColors(true);
        view_studies->setSelectionMode(QAbstractItemView::SingleSelection);
        view_studies->setSortingEnabled(true);
        view_studies->verticalHeader()->setVisible(false);

        gridLayout->addWidget(view_studies, 3, 1, 1, 1);

        label_patients = new QLabel(centralWidget);
        label_patients->setObjectName(QStringLiteral("label_patients"));

        gridLayout->addWidget(label_patients, 0, 1, 1, 1);

        label_worklists = new QLabel(centralWidget);
        label_worklists->setObjectName(QStringLiteral("label_worklists"));

        gridLayout->addWidget(label_worklists, 0, 0, 1, 1);

        view_worklists = new QTreeView(centralWidget);
        view_worklists->setObjectName(QStringLiteral("view_worklists"));
        view_worklists->setMinimumSize(QSize(300, 0));
        view_worklists->setMaximumSize(QSize(300, 16777215));
        view_worklists->setEditTriggers(QAbstractItemView::EditKeyPressed);
        view_worklists->setRootIsDecorated(true);
        view_worklists->setHeaderHidden(true);

        gridLayout->addWidget(view_worklists, 1, 0, 5, 1);

        view_patients = new QTableView(centralWidget);
        view_patients->setObjectName(QStringLiteral("view_patients"));
        view_patients->setEnabled(true);
        view_patients->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::EditKeyPressed);
        view_patients->setAlternatingRowColors(true);
        view_patients->setSelectionMode(QAbstractItemView::SingleSelection);
        view_patients->setSortingEnabled(true);
        view_patients->horizontalHeader()->setCascadingSectionResizes(true);
        view_patients->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        view_patients->horizontalHeader()->setStretchLastSection(true);
        view_patients->verticalHeader()->setVisible(false);
        view_patients->verticalHeader()->setDefaultSectionSize(33);
        view_patients->verticalHeader()->setMinimumSectionSize(20);

        gridLayout->addWidget(view_patients, 1, 1, 1, 1);

        view_images = new QListView(centralWidget);
        view_images->setObjectName(QStringLiteral("view_images"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(view_images->sizePolicy().hasHeightForWidth());
        view_images->setSizePolicy(sizePolicy);
        view_images->setEditTriggers(QAbstractItemView::EditKeyPressed);
        view_images->setIconSize(QSize(200, 200));
        view_images->setResizeMode(QListView::Adjust);
        view_images->setLayoutMode(QListView::Batched);
        view_images->setSpacing(0);
        view_images->setGridSize(QSize(250, 250));
        view_images->setViewMode(QListView::IconMode);
        view_images->setUniformItemSizes(true);

        gridLayout->addWidget(view_images, 5, 1, 1, 1);

        label_images = new QLabel(centralWidget);
        label_images->setObjectName(QStringLiteral("label_images"));

        gridLayout->addWidget(label_images, 4, 1, 1, 1);

        WorklistWindowLayout->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(WorklistWindowLayout);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1113, 24));
        menuStart = new QMenu(menuBar);
        menuStart->setObjectName(QStringLiteral("menuStart"));
        WorklistWindowLayout->setMenuBar(menuBar);
        statusBar = new QStatusBar(WorklistWindowLayout);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        WorklistWindowLayout->setStatusBar(statusBar);

        menuBar->addAction(menuStart->menuAction());
        menuStart->addAction(action_open_file);
        menuStart->addAction(action_open_folder);
        menuStart->addAction(action_open_external);

        retranslateUi(WorklistWindowLayout);

        QMetaObject::connectSlotsByName(WorklistWindowLayout);
    } // setupUi

    void retranslateUi(QMainWindow *WorklistWindowLayout)
    {
        WorklistWindowLayout->setWindowTitle(QApplication::translate("WorklistWindowLayout", "Worklistinterface", nullptr));
        action_open_file->setText(QApplication::translate("WorklistWindowLayout", "Open File", nullptr));
        action_open_folder->setText(QApplication::translate("WorklistWindowLayout", "Open Folder", nullptr));
        action_open_external->setText(QApplication::translate("WorklistWindowLayout", "Open External", nullptr));
        label_studies->setText(QApplication::translate("WorklistWindowLayout", "Studies", nullptr));
        label_patients->setText(QApplication::translate("WorklistWindowLayout", "Patients", nullptr));
        label_worklists->setText(QApplication::translate("WorklistWindowLayout", "Worklists", nullptr));
        label_images->setText(QApplication::translate("WorklistWindowLayout", "Images", nullptr));
        menuStart->setTitle(QApplication::translate("WorklistWindowLayout", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorklistWindowLayout: public Ui_WorklistWindowLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKLISTWINDOWLAYOUT_H