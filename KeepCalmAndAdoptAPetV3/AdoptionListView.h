#pragma once

#include <QDialog>
#include <QTableView>
#include <QVBoxLayout>
#include "AdoptionListModel.h"
#include "AdoptionList.h"

class AdoptionListView : public QDialog {
    Q_OBJECT

private:
    QTableView* tableView;
    AdoptionListModel* model;
    AdoptionList& adoptionList;

public:
    AdoptionListView(AdoptionList& adoptionList, QWidget* parent = nullptr)
        : QDialog(parent), adoptionList(adoptionList) {
        this->setWindowTitle("Adoption List");

        tableView = new QTableView(this);
        model = new AdoptionListModel(adoptionList, this);
        tableView->setModel(model);

        tableView->resizeColumnsToContents();

        int totalColumnWidth = 0;
        for (int i = 0; i < model->columnCount(); ++i) {
            totalColumnWidth += tableView->columnWidth(i);
        }

        int dialogWidth = totalColumnWidth + 50;
        setMinimumWidth(dialogWidth);

        QVBoxLayout* layout = new QVBoxLayout(this);
        layout->addWidget(tableView);
        this->setLayout(layout);

        connect(&adoptionList, &AdoptionList::adoptionListUpdated, model, &AdoptionListModel::onAdoptionListUpdated);
    }
};
