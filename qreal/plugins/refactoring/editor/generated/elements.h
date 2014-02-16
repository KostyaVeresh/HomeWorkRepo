#pragma once

#include <QBrush>
#include <QPainter>

#include "../../../../qrgui/editorPluginInterface/elementImpl.h"
#include "../../../../qrgui/editorPluginInterface/elementRepoInterface.h"
#include "../../../../qrgui/editorPluginInterface/labelFactoryInterface.h"
#include "../../../../qrgui/editorPluginInterface/labelInterface.h"
#include "ports.h"

	class AfterBlock : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/AfterBlockClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(200);
			contents.setHeight(200);
			ports << portFactory.createPort(QPointF(0, 0.5), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(0.5, 0), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(1, 0.5), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(0.5, 1), false, false, 200, 200, new NonTyped());
			title_1 = factory.createLabel(1, 0.025, 0.025, QString::fromUtf8("<b>AFTER</b>"), 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~AfterBlock() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return true;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
	};

	class BeforeBlock : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/BeforeBlockClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(200);
			contents.setHeight(200);
			ports << portFactory.createPort(QPointF(0, 0.5), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(0.5, 0), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(1, 0.5), false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QPointF(0.5, 1), false, false, 200, 200, new NonTyped());
			title_1 = factory.createLabel(1, 0.025, 0.025, QString::fromUtf8("<b>BEFORE</b>"), 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~BeforeBlock() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return true;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
	};

	class Element : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/ElementClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(80);
			contents.setHeight(80);
			ports << portFactory.createPort(QLineF(0, 0.125, 0, 0.875), false, false, false, false, 80, 80, new NonTyped());
			ports << portFactory.createPort(QLineF(0.125, 0, 0.875, 0), false, false, false, false, 80, 80, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.125, 1, 0.875), false, false, false, false, 80, 80, new NonTyped());
			ports << portFactory.createPort(QLineF(0.125, 1, 0.875, 1), false, false, false, false, 80, 80, new NonTyped());
			title_1 = factory.createLabel(1, 1, 0, "ID", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
			title_2 = factory.createLabel(2, 0.0625, 0.0625, "name", false, 0);
			title_2->setBackground(Qt::transparent);
			title_2->setScaling(false, false);
			title_2->setHard(false);
			title_2->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_2);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~Element() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			title_1->setTextFromRepo(repo->logicalProperty("ID"));
			title_2->setTextFromRepo(repo->name());
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
		qReal::LabelInterface *title_2;
	};

	class FromBeforeToAter : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(titles);
			Q_UNUSED(factory);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/FromBeforeToAterClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(100);
			contents.setHeight(100);
			ports << portFactory.createPort(QLineF(0.3, 0, 0.7, 0), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0, 0.3, 0, 0.7), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.3, 1, 0.7), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0.3, 1, 0.7, 1), false, false, false, false, 100, 100, new NonTyped());
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~FromBeforeToAter() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return false;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
	};

	class Link : public qReal::ElementImpl {
	public:
		void init(QRectF &, PortFactoryInterface const &, QList<PortInterface *> &,
											qReal::LabelFactoryInterface &, QList<qReal::LabelInterface *> &,
											qReal::SdfRendererInterface *, qReal::ElementRepoInterface *) {}

		void init(qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles)
		{
			title_1 = factory.createLabel(1, 0, 0, "ID", false, 0);
			title_1->setBackground(Qt::white);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		virtual ~Link() {}

		qReal::ElementImpl *clone() { return NULL; }
		void paint(QPainter *, QRectF &){}
		bool isNode() const { return false; }
		bool isResizeable() const { return true; }
		bool isContainer() const { return false; }
		bool isDividable() const { return false; }
		bool isSortingContainer() const { return false; }
		QVector<int> sizeOfForestalling() const { return QVector<int>(4, 0); }
		int sizeOfChildrenForestalling() const { return 0; }
		bool hasMovableChildren() const { return false; }
		bool minimizesToChildren() const { return false; }
		bool maximizesChildren() const { return false; }
		QStringList fromPortTypes() const
		{
			QStringList result;
			result << "NonTyped";
			return result;
		}
		QStringList toPortTypes() const
		{
			QStringList result;
			result << "NonTyped";
			return result;
		}
		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}
		bool isPort() const { return false; }
		bool hasPin() const { return false; }
		bool createChildrenFromMenu() const { return false; }
		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}
		int getPenWidth() const { return 1; }
		QColor getPenColor() const { return QColor(0,0,0); }
		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }
		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	protected:
		virtual void drawStartArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			painter->setBrush(old);
		}

		virtual void drawEndArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			static const QPointF points[] = {
				QPointF(-5,10),
				QPointF(0,0),
				QPointF(5,10)
			};
			painter->drawPolyline(points, 3);
			painter->setBrush(old);
		}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			title_1->setTextFromRepo(repo->logicalProperty("ID"));
		}

	private:
		qReal::LabelInterface *title_1;
	};

	class RefactoringDiagramNode : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/RefactoringDiagramNodeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(100);
			contents.setHeight(100);
			ports << portFactory.createPort(QLineF(0.3, 0, 0.7, 0), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0, 0.3, 0, 0.7), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.3, 1, 0.7), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0.3, 1, 0.7, 1), false, false, false, false, 100, 100, new NonTyped());
			title_1 = factory.createLabel(1, 0.05, 0.95, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~RefactoringDiagramNode() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			title_1->setTextFromRepo(repo->name());
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
	};

	class SelectedSegment : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/SelectedSegmentClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(80);
			contents.setHeight(80);
			ports << portFactory.createPort(QLineF(0, 0.125, 0, 0.875), false, false, false, false, 80, 80, new NonTyped());
			ports << portFactory.createPort(QLineF(0.125, 0, 0.875, 0), false, false, false, false, 80, 80, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.125, 1, 0.875), false, false, false, false, 80, 80, new NonTyped());
			ports << portFactory.createPort(QLineF(0.125, 1, 0.875, 1), false, false, false, false, 80, 80, new NonTyped());
			title_1 = factory.createLabel(1, 1, 0, "ID", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
			title_2 = factory.createLabel(2, 0.0625, 0.0625, QString::fromUtf8("<b>SELECTED</b>"), 0);
			title_2->setBackground(Qt::transparent);
			title_2->setScaling(false, false);
			title_2->setHard(false);
			title_2->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_2);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~SelectedSegment() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		int getPenWidth() const { return 0; }

		QColor getPenColor() const { return QColor(); }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			mRenderer->setElementRepo(repo);
			title_1->setTextFromRepo(repo->logicalProperty("ID"));
			Q_UNUSED(repo);
		}

		bool isNode() const
		{
			return true;
		}

		bool isResizeable() const
		{
			return true;
		}

		bool isContainer() const
		{
			return false;
		}

		bool isSortingContainer() const
		{
			return false;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 0 << 0 << 0 << 0;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isDividable() const
		{
			return false;
		}

		QStringList fromPortTypes() const
		{
			return QStringList("NonTyped");
		}

		QStringList toPortTypes() const
		{
			return QStringList("NonTyped");
		}

		enums::linkShape::LinkShape shapeType() const
		{
			return enums::linkShape::square;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
		{
			return false;
		}

		bool createChildrenFromMenu() const
		{
			return false;
		}

		QList<double> border() const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}

		QStringList bonusContextMenuFields() const
		{
			return QStringList();
		}

	private:
		qReal::SdfRendererInterface *mRenderer;
		qReal::LabelInterface *title_1;
		qReal::LabelInterface *title_2;
	};

