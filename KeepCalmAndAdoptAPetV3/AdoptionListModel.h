#include <QAbstractTableModel>
#include <vector>
#include <QString>
#include "AdoptionList.h"

class AdoptionListModel : public QAbstractTableModel {
    Q_OBJECT

private:
    AdoptionList& adoptionList;

public:
    AdoptionListModel(AdoptionList& adoptionList, QObject* parent = nullptr)
        : QAbstractTableModel(parent), adoptionList(adoptionList) {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        return static_cast<int>(adoptionList.getAdoptionList().size());
    }

    int columnCount(const QModelIndex& parent = QModelIndex()) const override {
        return 4; // Name, Breed, Age, Photo
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || role != Qt::DisplayRole)
            return QVariant();

        const std::vector<Dog>& dogs = adoptionList.getAdoptionList();
        const Dog& dog = dogs[index.row()];

        switch (index.column()) {
            case 0: return QString::fromStdString(dog.getName());
            case 1: return QString::fromStdString(dog.getBreed());
            case 2: return dog.getAge();
            case 3: return QString::fromStdString(dog.getPhotograph());
            default: return QVariant();
        }
    }

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return QString("Name");
                case 1: return QString("Breed");
                case 2: return QString("Age");
                case 3: return QString("Photo");
                default: return QVariant();
            }
        }
        return QVariant();
    }

public slots:
    void onAdoptionListUpdated() {
        beginResetModel();
        endResetModel();
    }
};
