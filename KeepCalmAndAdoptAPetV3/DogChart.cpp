#include "DogChart.h"

DogChart::DogChart(std::vector<Dog> dogs): dogs(dogs) {
	QMap<QString, int> dogCounts;
	for (int i = 0; i < dogs.size(); i++) {
		std::string breed = dogs[i].getBreed();
		dogCounts[QString::fromStdString(breed)] = filterBreed(dogs, breed).size();
	}

	QCustomPlot* plot = new QCustomPlot(this);
	plot->setMinimumSize(1000, 300);

	QVector<double> ticks;
	QVector<QString> labels;
	QVector<double> data;
	int i = 0;
	for (auto it = dogCounts.constBegin(); it != dogCounts.constEnd(); it++) {
		ticks << i;
		labels << it.key();
		data << it.value();
		i++;
	}

	QCPBars* bars = new QCPBars(plot->xAxis, plot->yAxis);
	plot->addGraph();
	plot->graph()->setAdaptiveSampling(true);
	plot->graph()->setData(ticks, data);
	plot->graph()->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black), QBrush(Qt::white), 7));
	plot->graph()->setLineStyle(QCPGraph::lsLine);
	plot->graph()->setPen(QPen(QColor(50, 50, 200, 150)));
	plot->graph()->setName("Dog Breeds");
	plot->graph()->setBrush(QColor(50, 50, 200, 150));


	QSharedPointer<QCPAxisTickerText> ticker(new QCPAxisTickerText);
	ticker->setTicks(ticks, labels);
	plot->xAxis->setTicker(ticker);
	plot->xAxis->setTickLabelRotation(0);
	plot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
	plot->xAxis->setTickLength(0, 4);
	plot->xAxis->grid()->setVisible(true);
	plot->xAxis->setRange(-0.5, dogCounts.size() - 0.5);
	plot->xAxis->setLabel("Dog Breeds");


	QVector<QString> numberlabels;
	int j = 0;
	for (auto it = dogCounts.constBegin(); it != dogCounts.constEnd(); ++it) {
		ticks << j;
		numberlabels << QString::number(it.value());
		data << it.value();
		j++;
	}
	QSharedPointer<QCPAxisTickerText> yTicker(new QCPAxisTickerText);
	yTicker->setTicks(data, numberlabels);
	plot->yAxis->setTicker(yTicker);
	plot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));
	plot->yAxis->setTickLength(0, 4);
	plot->yAxis->grid()->setVisible(true);
	plot->yAxis->setRange(0, *std::max_element(data.constBegin(), data.constEnd()) + 2);
	plot->yAxis->setLabel("Number of Dogs");

	plot->plotLayout()->insertRow(0);
	QCPTextElement* title = new QCPTextElement(plot, "Dog Breed Distribution", QFont("sans", 12, QFont::Bold));
	plot->plotLayout()->addElement(0, 0, title);

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(plot);
	setLayout(layout);
}

std::vector<Dog> DogChart::filterBreed(std::vector<Dog>& dog_list, std::string breed) {
	if (breed.length() == 0)
		return dog_list;
	std::vector<Dog> filtered;
	for (int i = 0; i < dog_list.size(); i++)
		if (compareStrings(dog_list[i].getBreed(), breed))
			filtered.push_back(dog_list[i]);
	return filtered;
}
