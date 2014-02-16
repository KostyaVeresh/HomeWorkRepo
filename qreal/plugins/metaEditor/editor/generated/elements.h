#pragma once

#include <QBrush>
#include <QPainter>

#include "../../../../qrgui/editorPluginInterface/elementImpl.h"
#include "../../../../qrgui/editorPluginInterface/elementRepoInterface.h"
#include "../../../../qrgui/editorPluginInterface/labelFactoryInterface.h"
#include "../../../../qrgui/editorPluginInterface/labelInterface.h"
#include "ports.h"

	class Container : public qReal::ElementImpl {
	public:
		void init(QRectF &, PortFactoryInterface const &, QList<PortInterface *> &,
											qReal::LabelFactoryInterface &, QList<qReal::LabelInterface *> &,
											qReal::SdfRendererInterface *, qReal::ElementRepoInterface *) {}

		void init(qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles)
		{
			Q_UNUSED(titles);
			Q_UNUSED(factory);
		}

		virtual ~Container() {}

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
			static const QPointF points[] = {
				QPointF(-5,10),
				QPointF(0,0),
				QPointF(5,10)
			};
			painter->drawPolyline(points, 3);
			painter->setBrush(old);
		}

		virtual void drawEndArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			painter->setBrush(old);
		}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			Q_UNUSED(repo);
		}

	private:
	};

	class Explosion : public qReal::ElementImpl {
	public:
		void init(QRectF &, PortFactoryInterface const &, QList<PortInterface *> &,
											qReal::LabelFactoryInterface &, QList<qReal::LabelInterface *> &,
											qReal::SdfRendererInterface *, qReal::ElementRepoInterface *) {}

		void init(qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles)
		{
			Q_UNUSED(titles);
			Q_UNUSED(factory);
		}

		virtual ~Explosion() {}

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
			brush.setColor(Qt::black);
			painter->setBrush(brush);
			static const QPointF points[] = {
				QPointF(0,0),
				QPointF(-5,10),
				QPointF(5,10)
			};
			painter->drawPolygon(points, 3);
			painter->setBrush(old);
		}

		virtual void drawEndArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			painter->setBrush(old);
		}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			Q_UNUSED(repo);
		}

	private:
	};

	class Inheritance : public qReal::ElementImpl {
	public:
		void init(QRectF &, PortFactoryInterface const &, QList<PortInterface *> &,
											qReal::LabelFactoryInterface &, QList<qReal::LabelInterface *> &,
											qReal::SdfRendererInterface *, qReal::ElementRepoInterface *) {}

		void init(qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles)
		{
			Q_UNUSED(titles);
			Q_UNUSED(factory);
		}

		virtual ~Inheritance() {}

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
			brush.setColor(Qt::white);
			painter->setBrush(brush);
			static const QPointF points[] = {
				QPointF(0,0),
				QPointF(-5,10),
				QPointF(5,10)
			};
			painter->drawPolygon(points, 3);
			painter->setBrush(old);
		}

		virtual void drawEndArrow(QPainter * painter) const
		{
			QBrush old = painter->brush();
			QBrush brush;
			brush.setStyle(Qt::SolidPattern);
			painter->setBrush(brush);
			painter->setBrush(old);
		}

		void updateData(qReal::ElementRepoInterface *repo) const
		{
			Q_UNUSED(repo);
		}

	private:
	};

	class Listener : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/ListenerClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(250);
			contents.setHeight(80);
			title_1 = factory.createLabel(1, 0.02, 0.0375, "class", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
			title_2 = factory.createLabel(2, 0.02, 0.625, "file", false, 0);
			title_2->setBackground(Qt::transparent);
			title_2->setScaling(false, false);
			title_2->setHard(false);
			title_2->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_2);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~Listener() {}

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
			title_1->setTextFromRepo(repo->logicalProperty("class"));
			title_2->setTextFromRepo(repo->logicalProperty("file"));
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

	class MetaEditorDiagramNode : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEditorDiagramNodeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(200);
			contents.setHeight(200);
			ports << portFactory.createPort(QLineF(0, 0.2, 0, 0.8), false, false, false, false, 200, 200, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.2, 1, 0.8), false, false, false, false, 200, 200, new NonTyped());
			title_1 = factory.createLabel(1, 0.15, 0.075, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEditorDiagramNode() {}

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
			return true;
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

	class MetaEntity_Attribute : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntity_AttributeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(140);
			contents.setHeight(16);
			title_1 = factory.createLabel(1, 0.0714286, 0, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntity_Attribute() {}

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
			return true;
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

	class MetaEntityAssociation : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityAssociationClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(120);
			contents.setHeight(40);
			title_1 = factory.createLabel(1, 0.0833333, 0.125, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityAssociation() {}

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
			return true;
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

	class MetaEntityConnection : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityConnectionClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(120);
			contents.setHeight(40);
			title_1 = factory.createLabel(1, 0.0833333, 0.125, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityConnection() {}

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
			return true;
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

	class MetaEntityContextMenuField : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			Q_UNUSED(titles);
			Q_UNUSED(factory);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityContextMenuFieldClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(100);
			contents.setHeight(30);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityContextMenuField() {}

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

	class MetaEntityEdge : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityEdgeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(100);
			contents.setHeight(100);
			ports << portFactory.createPort(QLineF(0, 0.5, 0.05, 0.25), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0, 0.5, 0.05, 0.75), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.5, 0.95, 0.25), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.5, 0.95, 0.75), false, false, false, false, 100, 100, new NonTyped());
			title_1 = factory.createLabel(1, 0.05, 0.05, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityEdge() {}

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
			return true;
		}

		bool isSortingContainer() const
		{
			return true;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 25 << 35 << 25 << 25;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 5;
		}

		bool hasMovableChildren() const
		{
			return false;
		}

		bool minimizesToChildren() const
		{
			return true;
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
			return true;
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

	class MetaEntityEnum : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityEnumClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(100);
			contents.setHeight(100);
			ports << portFactory.createPort(QLineF(0, 0.2, 0, 0.8), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.2, 1, 0.8), false, false, false, false, 100, 100, new NonTyped());
			title_1 = factory.createLabel(1, 0.05, 0.03, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityEnum() {}

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
			return true;
		}

		bool isSortingContainer() const
		{
			return true;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 5 << 25 << 5 << 5;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 5;
		}

		bool hasMovableChildren() const
		{
			return false;
		}

		bool minimizesToChildren() const
		{
			return true;
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
			return true;
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

	class MetaEntityImport : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityImportClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(100);
			contents.setHeight(100);
			ports << portFactory.createPort(QLineF(0.2, 0, 0.8, 0), false, false, false, false, 100, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0.2, 1, 0.8, 1), false, false, false, false, 100, 100, new NonTyped());
			title_1 = factory.createLabel(1, 0.1, 0.1, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityImport() {}

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
			return true;
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

	class MetaEntityNode : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityNodeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(150);
			contents.setHeight(100);
			ports << portFactory.createPort(QLineF(0, 0.1, 0, 0.9), false, false, false, false, 150, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.1, 1, 0.9), false, false, false, false, 150, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0.0666667, 0, 0.933333, 0), false, false, false, false, 150, 100, new NonTyped());
			ports << portFactory.createPort(QLineF(0.0666667, 1, 0.933333, 1), false, false, false, false, 150, 100, new NonTyped());
			title_1 = factory.createLabel(1, 0.0333333, 0.03, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityNode() {}

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
			return true;
		}

		bool isSortingContainer() const
		{
			return true;
		}

		QVector<int> sizeOfForestalling() const
		{
			QVector<int> result;
			result << 25 << 35 << 25 << 25;
;
			return result;
		}

		int sizeOfChildrenForestalling() const
		{
			return 5;
		}

		bool hasMovableChildren() const
		{
			return false;
		}

		bool minimizesToChildren() const
		{
			return true;
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
			return true;
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

	class MetaEntityPort : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityPortClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(50);
			contents.setHeight(50);
			title_1 = factory.createLabel(1, 0.04, 0.4, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, true);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityPort() {}

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
			return true;
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

	class MetaEntityPossibleEdge : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			Q_UNUSED(titles);
			Q_UNUSED(factory);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityPossibleEdgeClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(25);
			contents.setHeight(25);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityPossibleEdge() {}

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

	class MetaEntityPropertiesAsContainer : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			Q_UNUSED(titles);
			Q_UNUSED(factory);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityPropertiesAsContainerClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(50);
			contents.setHeight(50);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityPropertiesAsContainer() {}

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

	class MetaEntityUsage : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityUsageClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(120);
			contents.setHeight(40);
			title_1 = factory.createLabel(1, 0.0833333, 0.125, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityUsage() {}

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
			return true;
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

	class MetaEntityValue : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			Q_UNUSED(portFactory);
			Q_UNUSED(ports);
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/MetaEntityValueClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(140);
			contents.setHeight(12);
			title_1 = factory.createLabel(1, 0.0714286, 0, "valueName", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetaEntityValue() {}

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
			title_1->setTextFromRepo(repo->logicalProperty("valueName"));
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
			return true;
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

	class MetamodelDiagram : public qReal::ElementImpl
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
			mRenderer->load(QString(":/generated/shapes/MetamodelDiagramClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(30);
			contents.setHeight(30);
			ports << portFactory.createPort(QPointF(0, 1.66667), false, false, 30, 30, new NonTyped());
			ports << portFactory.createPort(QPointF(1.66667, 0), false, false, 30, 30, new NonTyped());
			ports << portFactory.createPort(QPointF(3.33333, 1.66667), false, false, 30, 30, new NonTyped());
			ports << portFactory.createPort(QPointF(1.66667, 3.33333), false, false, 30, 30, new NonTyped());
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~MetamodelDiagram() {}

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
			return true;
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

	class PackageDiagram : public qReal::ElementImpl
	{
	public:
		void init(qReal::LabelFactoryInterface &, QList<qReal::LabelInterface*> &) {}

		void init(QRectF &contents, PortFactoryInterface const &portFactory, QList<PortInterface *> &ports
							, qReal::LabelFactoryInterface &factory, QList<qReal::LabelInterface*> &titles
							, qReal::SdfRendererInterface *renderer, qReal::ElementRepoInterface *elementRepo)
		{
			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/PackageDiagramClass.sdf"));
			mRenderer->setElementRepo(elementRepo);
			contents.setWidth(150);
			contents.setHeight(130);
			ports << portFactory.createPort(QLineF(0, 0.269231, 0, 0.884615), false, false, false, false, 150, 130, new NonTyped());
			ports << portFactory.createPort(QLineF(1, 0.269231, 1, 0.884615), false, false, false, false, 150, 130, new NonTyped());
			title_1 = factory.createLabel(1, 0.0133333, 0.0153846, "name", false, 0);
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setHard(false);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);
		}

		 qReal::ElementImpl *clone() { return NULL; }
		~PackageDiagram() {}

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
			return true;
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

