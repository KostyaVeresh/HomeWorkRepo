#pragma once

#include <QBrush>
#include <QPainter>

#include "../../../qrgui/editorPluginInterface/elementImpl.h"
#include "../../../qrgui/editorPluginInterface/elementTitleHelpers.h"
#include "../../../qrgui/editorPluginInterface/elementRepoInterface.h"
#include "../../../qrgui/umllib/element.h"

	class SimpleDiagram : public ElementImpl
	{
	public:

		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
				QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
				QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
				SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(pointPorts)
			Q_UNUSED(linePorts)

			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/SimpleDiagramClass.sdf"));
			Q_UNUSED(portRenderer)
			contents.setWidth(187);
			contents.setHeight(185);
			StatPoint pt;

			title_1 = factory.createTitle(0.171123, 0.216216, "name");
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);

		}

		~SimpleDiagram() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return @@NodeHasPorts@@;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			title_1->setHtml(QString("<b>%1</b>").arg(repo->name()));

		}

		bool isNode() const
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

		int sizeOfForestalling() const
		{
			return 0;
		}       

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
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

		bool isResizeable() const
		{
			return true;
		}

		int getPenWidth() const
		{ 
			return 0; 
		}

		QColor getPenColor() const 
		{ 
			return QColor(); 
		}

		bool isDividable() const
		{
			return false;
		}

	private:
		SdfRendererInterface *mRenderer;
		QStringList mBonusContextMenuFields;
		ElementTitleInterface *title_1;

	};



	class SimpleNode : public ElementImpl
	{
	public:

		void init(ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &) {}

		void init(QRectF &contents, QList<StatPoint> &pointPorts,
				QList<StatLine> &linePorts, ElementTitleFactoryInterface &factory,
				QList<ElementTitleInterface*> &titles, SdfRendererInterface *renderer,
				SdfRendererInterface *portRenderer)
		{
			Q_UNUSED(linePorts)

			mRenderer = renderer;
			mRenderer->load(QString(":/generated/shapes/SimpleNodeClass.sdf"));
			portRenderer->load(QString(":/generated/shapes/SimpleNodePorts.sdf"));
			contents.setWidth(259);
			contents.setHeight(198);
			StatPoint pt;
			pt.point = QPointF(0.00772201, 0.469697); 
			pointPorts << pt;
			pt.point = QPointF(0.505792, 0.010101); 
			pointPorts << pt;
			pt.point = QPointF(0.486486, 0.984848); 
			pointPorts << pt;
			pt.point = QPointF(0.988417, 0.505051); 
			pointPorts << pt;

			title_1 = factory.createTitle(0.111969, 0.116162, "name");
			title_1->setBackground(Qt::transparent);
			title_1->setScaling(false, false);
			title_1->setFlags(0);
			title_1->setTextInteractionFlags(Qt::NoTextInteraction);
			titles.append(title_1);

		}

		~SimpleNode() {}

		void paint(QPainter *painter, QRectF &contents)
		{
			mRenderer->render(painter, contents);
		}

		Qt::PenStyle getPenStyle() const { return Qt::SolidLine; }

		void drawStartArrow(QPainter *) const {}
		void drawEndArrow(QPainter *) const {}
		bool hasPorts() const
		{
			return @@NodeHasPorts@@;
		}

		void updateData(ElementRepoInterface *repo) const
		{
			title_1->setHtml(QString("<b>%1</b>").arg(repo->name()));

		}

		bool isNode() const
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

		int sizeOfForestalling() const
		{
			return 0;
		}       

		int sizeOfChildrenForestalling() const
		{
			return 0;
		}

		bool minimizesToChildren() const
		{
			return false;
		}

		bool hasMovableChildren() const
		{
			return true;
		}

		bool maximizesChildren() const
		{
			return false;
		}

		bool isPort() const
		{
			return false;
		}

		bool hasPin() const
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

		bool isResizeable() const
		{
			return true;
		}

		int getPenWidth() const
		{ 
			return 0; 
		}

		QColor getPenColor() const 
		{ 
			return QColor(); 
		}

		bool isDividable() const
		{
			return false;
		}

	private:
		SdfRendererInterface *mRenderer;
		QStringList mBonusContextMenuFields;
		ElementTitleInterface *title_1;

	};





	class SimpleEdge : public ElementImpl {
	public:
		void init(QRectF &, QList<StatPoint> &, QList<StatLine> &,
				ElementTitleFactoryInterface &, QList<ElementTitleInterface*> &,
				SdfRendererInterface *, SdfRendererInterface *) {}

		void init(ElementTitleFactoryInterface &factory, QList<ElementTitleInterface*> &titles)
		{
			Q_UNUSED(factory)
			Q_UNUSED(titles)

		}

		virtual ~SimpleEdge() {}

		void paint(QPainter *, QRectF &){}
		bool isNode() const { return false; }
		bool isContainer() const { return false; }
		bool isSortingContainer() const { return false; }
		int sizeOfForestalling() const { return 0; }
		int sizeOfChildrenForestalling() const { return 0; }
		bool hasMovableChildren() const { return false; }
		bool minimizesToChildren() const { return false; }
		bool isClass() { return false; }
		bool maximizesChildren() const { return false; }
		bool isPort() const { return false; }
		bool hasPin() const { return false; }
		bool isResizeable() const { return true; }
		int getPenWidth() const { return 1; }
		QColor getPenColor() const { return QColor(); }
		bool isDividable() const { return false; }
		QList<double> border () const
		{
			QList<double> list;
			list << 0 << 0 << 0 << 0;
			return list;
		}
		bool hasPorts() const { return false; }
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

			painter->setBrush(old);
		}

		void updateData(ElementRepoInterface *repo) const
		{
			Q_UNUSED(repo)

		}

	private:

	};





