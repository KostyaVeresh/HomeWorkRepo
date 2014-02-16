#include "pluginInterface.h"

#include "elements.h"


MetaEditorPlugin::MetaEditorPlugin()
{
	initPlugin();
}

void MetaEditorPlugin::initPlugin()
{
	initNameMap();
	initMouseGestureMap();
	initPropertyMap();
	initPropertyDefaultsMap();
	initDescriptionMap();
	initParentsMap();
	initPaletteGroupsMap();
	initPaletteGroupsDescriptionMap();
	initShallPaletteBeSortedMap();
	initExplosionsMap();
}

void MetaEditorPlugin::initNameMap()
{
	mDiagramNameMap["MetaEditor"] = QString::fromUtf8("Meta Editor");
	mDiagramNodeNameMap["MetaEditor"] = "MetamodelDiagram";

	mElementsNameMap["MetaEditor"]["Container"] = QString::fromUtf8("Container");
	mElementsNameMap["MetaEditor"]["Explosion"] = QString::fromUtf8("Explodes To");
	mElementsNameMap["MetaEditor"]["Inheritance"] = QString::fromUtf8("Inheritance");
	mElementsNameMap["MetaEditor"]["Listener"] = QString::fromUtf8("Listener");
	mElementsNameMap["MetaEditor"]["MetaEditorDiagramNode"] = QString::fromUtf8("Meta Editor Diagram");
	mElementsNameMap["MetaEditor"]["MetaEntity_Attribute"] = QString::fromUtf8("Property");
	mElementsNameMap["MetaEditor"]["MetaEntityAssociation"] = QString::fromUtf8("Assotiation");
	mElementsNameMap["MetaEditor"]["MetaEntityConnection"] = QString::fromUtf8("Connection");
	mElementsNameMap["MetaEditor"]["MetaEntityContextMenuField"] = QString::fromUtf8("Context Menu Field");
	mElementsNameMap["MetaEditor"]["MetaEntityEdge"] = QString::fromUtf8("Edge");
	mElementsNameMap["MetaEditor"]["MetaEntityEnum"] = QString::fromUtf8("Enum");
	mElementsNameMap["MetaEditor"]["MetaEntityImport"] = QString::fromUtf8("Import");
	mElementsNameMap["MetaEditor"]["MetaEntityNode"] = QString::fromUtf8("Node");
	mElementsNameMap["MetaEditor"]["MetaEntityPort"] = QString::fromUtf8("Port");
	mElementsNameMap["MetaEditor"]["MetaEntityPossibleEdge"] = QString::fromUtf8("Possible Edge");
	mElementsNameMap["MetaEditor"]["MetaEntityPropertiesAsContainer"] = QString::fromUtf8("Properties as Container");
	mElementsNameMap["MetaEditor"]["MetaEntityUsage"] = QString::fromUtf8("Usage");
	mElementsNameMap["MetaEditor"]["MetaEntityValue"] = QString::fromUtf8("Value");
	mElementsNameMap["MetaEditor"]["MetamodelDiagram"] = QString::fromUtf8("Metamodel Diagram");
	mElementsNameMap["MetaEditor"]["PackageDiagram"] = QString::fromUtf8("Package Diagram");
	mPropertiesDisplayedNamesMap["MetaEditor"]["MetamodelDiagram"]["name of the directory"] = QString::fromUtf8("directory to generated code");
}

void MetaEditorPlugin::initPaletteGroupsMap()
{
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("MetaEntityNode");
		groupElements << QString::fromUtf8("MetaEntityEdge");
		groupElements << QString::fromUtf8("MetaEntityPort");
		groupElements << QString::fromUtf8("MetaEntityEnum");
		groupElements << QString::fromUtf8("MetaEntityImport");
		mPaletteGroupsMap[QString::fromUtf8("MetaEditor")].append(qMakePair(QString::fromUtf8("DSL Elements"), groupElements));
	}
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("MetamodelDiagram");
		groupElements << QString::fromUtf8("MetaEditorDiagramNode");
		groupElements << QString::fromUtf8("PackageDiagram");
		mPaletteGroupsMap[QString::fromUtf8("MetaEditor")].append(qMakePair(QString::fromUtf8("Root Diagrams"), groupElements));
	}
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("MetaEntity_Attribute");
		groupElements << QString::fromUtf8("MetaEntityPropertiesAsContainer");
		groupElements << QString::fromUtf8("MetaEntityPossibleEdge");
		mPaletteGroupsMap[QString::fromUtf8("MetaEditor")].append(qMakePair(QString::fromUtf8("Node Properties"), groupElements));
	}
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("MetaEntityValue");
		mPaletteGroupsMap[QString::fromUtf8("MetaEditor")].append(qMakePair(QString::fromUtf8("Enum Properties"), groupElements));
	}
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("MetaEntity_Attribute");
		groupElements << QString::fromUtf8("MetaEntityAssociation");
		mPaletteGroupsMap[QString::fromUtf8("MetaEditor")].append(qMakePair(QString::fromUtf8("Edge Properties"), groupElements));
	}
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("Inheritance");
		groupElements << QString::fromUtf8("Container");
		groupElements << QString::fromUtf8("Explosion");
		mPaletteGroupsMap[QString::fromUtf8("MetaEditor")].append(qMakePair(QString::fromUtf8("Relationship"), groupElements));
	}
}

void MetaEditorPlugin::initPaletteGroupsDescriptionMap()
{
	mPaletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("DSL Elements")] = QString::fromUtf8("Элементы метаязыка для описания узлов и связей создаваемого языка");
	mPaletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Edge Properties")] = QString::fromUtf8("Элементы метаязыка для указания свойств связей создаваемого языка");
	mPaletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Enum Properties")] = QString::fromUtf8("Элементы метаязыка для указания свойств перечисляемого типа создаваемого языка");
	mPaletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Node Properties")] = QString::fromUtf8("Элементы метаязыка для указания свойств узлов создаваемого языка");
	mPaletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Relationship")] = QString::fromUtf8("Связи метаязыка для описания вызимоотношений между элементами создаваемого языка");
	mPaletteGroupsDescriptionMap[QString::fromUtf8("MetaEditor")][QString::fromUtf8("Root Diagrams")] = QString::fromUtf8("Корневые элементы");
}

void MetaEditorPlugin::initMouseGestureMap()
{
}

void MetaEditorPlugin::initPropertyMap()
{
	mPropertyTypes["Container"]["ownedComment"] = "Comment";
	mPropertyTypes["Explosion"]["makeReusable"] = "Bool";
	mPropertyTypes["Explosion"]["ownedComment"] = "Comment";
	mPropertyTypes["Explosion"]["requireImmediateLinkage"] = "Bool";
	mPropertyTypes["Inheritance"]["ownedComment"] = "Comment";
	mPropertyTypes["MetaEditorDiagramNode"]["isView"] = "Bool";
	mPropertyTypes["MetaEntityAssociation"]["beginType"] = "AssociationTypes";
	mPropertyTypes["MetaEntityAssociation"]["endType"] = "AssociationTypes";
	mPropertyTypes["MetaEntityEdge"]["fromPorts"] = "MetaEntityPort";
	mPropertyTypes["MetaEntityEdge"]["labelType"] = "LabelTypes";
	mPropertyTypes["MetaEntityEdge"]["lineType"] = "LineTypes";
	mPropertyTypes["MetaEntityEdge"]["shape"] = "LinkShapeType";
	mPropertyTypes["MetaEntityEdge"]["toPorts"] = "MetaEntityPort";
	mPropertyTypes["MetaEntityNode"]["createChildrenFromMenu"] = "Bool";
	mPropertyTypes["MetaEntityNode"]["isAction"] = "Bool";
	mPropertyTypes["MetaEntityNode"]["isResizeable"] = "Bool";
	mPropertyTypes["MetaEntityNode"]["isView"] = "Bool";
	mPropertyTypes["MetaEntityPossibleEdge"]["directed"] = "Bool";
	mPropertyTypes["MetaEntityPropertiesAsContainer"]["banChildrenMove"] = "Bool";
	mPropertyTypes["MetaEntityPropertiesAsContainer"]["maximizeChildren"] = "Bool";
	mPropertyTypes["MetaEntityPropertiesAsContainer"]["minimizeToChildren"] = "Bool";
	mPropertyTypes["MetaEntityPropertiesAsContainer"]["sortContainer"] = "Bool";
	mPropertyTypes["MetamodelDiagram"]["name of the directory"] = "DirectoryPath";
	mPropertyTypes["MetamodelDiagram"]["path to QReal Source Files"] = "DirectoryPath";
	mPropertyTypes["PackageDiagram"]["isView"] = "Bool";
}

void MetaEditorPlugin::initPropertyDefaultsMap()
{
	mPropertyDefault["MetaEntityEdge"]["labelType"] = QString::fromUtf8("Dynamic text");
	mPropertyDefault["MetaEntityEdge"]["lineType"] = QString::fromUtf8("solidLine");
	mPropertyDefault["MetaEntityEdge"]["shape"] = QString::fromUtf8("square");
	mPropertyDefault["MetaEntityNode"]["isAction"] = QString::fromUtf8("false");
	mPropertyDefault["MetaEntityNode"]["isResizeable"] = QString::fromUtf8("true");
	mPropertyDefault["MetaEntityPossibleEdge"]["directed"] = QString::fromUtf8("false");
	mPropertyDefault["MetaEntityPropertiesAsContainer"]["banChildrenMove"] = QString::fromUtf8("false");
	mPropertyDefault["MetaEntityPropertiesAsContainer"]["maximizeChildren"] = QString::fromUtf8("false");
	mPropertyDefault["MetaEntityPropertiesAsContainer"]["minimizeToChildren"] = QString::fromUtf8("false");
	mPropertyDefault["MetaEntityPropertiesAsContainer"]["sortContainer"] = QString::fromUtf8("false");
}

void MetaEditorPlugin::initDescriptionMap()
{
	mElementsDescriptionMap["MetaEditor"]["Container"] = QString::fromUtf8("Связь, указывающая отношение вложенности между элементами (направления – от вкладываемого элемента к тому, в который вкладывается)");
	mElementsDescriptionMap["MetaEditor"]["Explosion"] = QString::fromUtf8("Связь, означающая 'раскрываемость' элемента в диаграмму (направление - от элемента, который раскрывается к элементу, являющимся корневым для диаграммы, в которую раскрывается элемент)");
	mElementsDescriptionMap["MetaEditor"]["Inheritance"] = QString::fromUtf8("Связь, указывающая отношение наследования между элементами (направление – от дочернего элемента к предку)");
	mElementsDescriptionMap["MetaEditor"]["Listener"] = QString::fromUtf8("Не поддерживается");
	mElementsDescriptionMap["MetaEditor"]["MetaEditorDiagramNode"] = QString::fromUtf8("Элемент для описания конкретного редактора создаваемого языка. Должен вкладываться в Metamodel Diagram");
	mElementsDescriptionMap["MetaEditor"]["MetaEntity_Attribute"] = QString::fromUtf8("Сущность для описания нового свойства элемента. Вкладывается в соответствующий элемент Node или Edge");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityAssociation"] = QString::fromUtf8("Элемент для указания типов и имен начала и конца связи (см. Edge). Вкладывается в соответствующий элемент Edge");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityConnection"] = QString::fromUtf8("Не поддерживается");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityContextMenuField"] = QString::fromUtf8("Не поддерживается");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityEdge"] = QString::fromUtf8("Элемент для описания новой связи на диаграмме создаваемого языка. Должен вкладываться в Meta Editor Diagram");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityEnum"] = QString::fromUtf8("Элемент для описания перечисляемого типа данных для создаваемого языка (см. Value). Вкладывается в Meta Editor Diagram");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityImport"] = QString::fromUtf8("Сущность для добавления в создаваемый язык элемента из другого визуального языка. Должен вкладываться в Metamodel Diagram.");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityNode"] = QString::fromUtf8("Элемент для описания нового узла диаграммы создаваемого языка. Должен вкладываться в Meta Editor Diagram");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityPort"] = QString::fromUtf8("Элемент для описания нового типа портов для элементов создаваемого языка. Должен вкладываться в Meta Editor Diagram");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityPossibleEdge"] = QString::fromUtf8("Сущность для указания элементов, которые можно присоединять к данному с помощью «вытягивания» из него связей. Вкладывается в соответствующий элемент Node");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityPropertiesAsContainer"] = QString::fromUtf8("Сущность для указания дополнительной функциональности элемента создаваемого языка, являющегося контейнером (см. Container). Вкладывается в соответствующий элемент типа Node");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityUsage"] = QString::fromUtf8("Не поддерживается");
	mElementsDescriptionMap["MetaEditor"]["MetaEntityValue"] = QString::fromUtf8("Сущность для описания конкретного значения для создаваемого перечисляемого типа (см. Enum). Должен вкладываться в Enum");
	mElementsDescriptionMap["MetaEditor"]["MetamodelDiagram"] = QString::fromUtf8("Корневой элемент метамодели языка. В его свойствах указываются необходимые для сборки параметры");
	mElementsDescriptionMap["MetaEditor"]["PackageDiagram"] = QString::fromUtf8("Предназначен для описания связей между метамоделями. Также может быть корневым элементом метамодели");
	mPropertiesDescriptionMap["MetaEditor"]["MetaEditorDiagramNode"]["nodeName"] = QString::fromUtf8("имя элемента, который будет корневым для диаграмм на создаваемом языке");
	mPropertiesDescriptionMap["MetaEditor"]["MetaEntityEdge"]["labelType"] = QString::fromUtf8("тип текста(статический, динамический)");
	mPropertiesDescriptionMap["MetaEditor"]["MetaEntityEdge"]["lineType"] = QString::fromUtf8("тип линии (прямая, пунктирная и т.д.)");
	mPropertiesDescriptionMap["MetaEditor"]["MetamodelDiagram"]["include"] = QString::fromUtf8("xml-файлы, которые следует подключить к создаваемой метамодели");
	mPropertiesDescriptionMap["MetaEditor"]["MetamodelDiagram"]["path to QReal Source Files"] = QString::fromUtf8("путь до исходных файлов QReal");
}

void MetaEditorPlugin::initParentsMap()
{
	mParentsMap["MetaEditor"]["Container"]
		<< qMakePair(QString("MetaEditor"), QString("Relationship"))
	;
	mParentsMap["MetaEditor"]["Explosion"]
		<< qMakePair(QString("MetaEditor"), QString("Relationship"))
	;
	mParentsMap["MetaEditor"]["Inheritance"]
		<< qMakePair(QString("MetaEditor"), QString("Relationship"))
	;
	mParentsMap["MetaEditor"]["MetaEditorDiagramNode"]
		<< qMakePair(QString("MetaEditor"), QString("Diagram"))
	;
	mParentsMap["MetaEditor"]["MetaEntityNode"]
		<< qMakePair(QString("MetaEditor"), QString("Diagram"))
	;
	mParentsMap["MetaEditor"]["PackageDiagram"]
		<< qMakePair(QString("MetaEditor"), QString("Diagram"))
	;
}

void MetaEditorPlugin::initShallPaletteBeSortedMap()
{
	mShallPaletteBeSortedMap[QString::fromUtf8("MetaEditor")] = true;
}

void MetaEditorPlugin::initExplosionsMap()
{
}

QStringList MetaEditorPlugin::diagrams() const
{
	return mDiagramNameMap.keys();
}

QStringList MetaEditorPlugin::diagramPaletteGroups(QString const &diagram) const
{
	QStringList result;
	for (QPair<QString, QStringList> const &group : mPaletteGroupsMap[diagram]) {
		result << group.first;
	}

	return result;
}

QStringList MetaEditorPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	for (QPair<QString, QStringList> const &ourGroup : mPaletteGroupsMap[diagram]) {
		if (ourGroup.first == group) {
			return ourGroup.second;
		}
	}

	return QStringList();
}

QString MetaEditorPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return mPaletteGroupsDescriptionMap[diagram][group];
}

bool MetaEditorPlugin::shallPaletteBeSorted(QString const &diagram) const
{
	return mShallPaletteBeSortedMap[diagram];
}

QStringList MetaEditorPlugin::elements(QString const &diagram) const
{
	return mElementsNameMap[diagram].keys();
}

QStringList MetaEditorPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return mPropertyDefault[element].keys();
}

QString MetaEditorPlugin::editorName() const
{
	 return "MetaEditor Editor";
}

QString MetaEditorPlugin::diagramName(QString const &diagram) const
{
	return mDiagramNameMap[diagram];
}

QString MetaEditorPlugin::diagramNodeName(QString const &diagram) const
{
	return mDiagramNodeNameMap[diagram];
}

QString MetaEditorPlugin::elementName(QString const &diagram, QString const &element) const
{
	return mElementsNameMap[diagram][element];
}

QString MetaEditorPlugin::elementDescription(QString const &diagram, QString const &element)const
{
	return mElementsDescriptionMap[diagram][element];
}

QString MetaEditorPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDescriptionMap[diagram][element][property];
}

QString MetaEditorPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDisplayedNamesMap[diagram][element][property];
}

QString MetaEditorPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return mElementMouseGesturesMap[diagram][element];
}

QList<qReal::EditorInterface::ExplosionData>MetaEditorPlugin::explosions(QString const &diagram, QString const &element) const 
{
	return mExplosionsMap[diagram][element];
}

qReal::ElementImpl* MetaEditorPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "Container") {
		return new Container();
	}
	else if (element == "Explosion") {
		return new Explosion();
	}
	else if (element == "Inheritance") {
		return new Inheritance();
	}
	else if (element == "Listener") {
		return new Listener();
	}
	else if (element == "MetaEditorDiagramNode") {
		return new MetaEditorDiagramNode();
	}
	else if (element == "MetaEntity_Attribute") {
		return new MetaEntity_Attribute();
	}
	else if (element == "MetaEntityAssociation") {
		return new MetaEntityAssociation();
	}
	else if (element == "MetaEntityConnection") {
		return new MetaEntityConnection();
	}
	else if (element == "MetaEntityContextMenuField") {
		return new MetaEntityContextMenuField();
	}
	else if (element == "MetaEntityEdge") {
		return new MetaEntityEdge();
	}
	else if (element == "MetaEntityEnum") {
		return new MetaEntityEnum();
	}
	else if (element == "MetaEntityImport") {
		return new MetaEntityImport();
	}
	else if (element == "MetaEntityNode") {
		return new MetaEntityNode();
	}
	else if (element == "MetaEntityPort") {
		return new MetaEntityPort();
	}
	else if (element == "MetaEntityPossibleEdge") {
		return new MetaEntityPossibleEdge();
	}
	else if (element == "MetaEntityPropertiesAsContainer") {
		return new MetaEntityPropertiesAsContainer();
	}
	else if (element == "MetaEntityUsage") {
		return new MetaEntityUsage();
	}
	else if (element == "MetaEntityValue") {
		return new MetaEntityValue();
	}
	else if (element == "MetamodelDiagram") {
		return new MetamodelDiagram();
	}
	else if (element == "PackageDiagram") {
		return new PackageDiagram();
	}
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool MetaEditorPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
{
	if (childDiagram == parentDiagram && childElement == parentElement)
		return true;
	if (mParentsMap[childDiagram][childElement].contains(qMakePair(parentDiagram, parentElement)))
		return true;
	typedef QPair<QString, QString> StringPair;
	foreach (StringPair const &pair, mParentsMap[childDiagram][childElement])
		if (isParentOf(parentDiagram, parentElement, pair.first, pair.second))
			return true;
	return false;
}
QList<QPair<QString, QString> > MetaEditorPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return mParentsMap[diagram][element];
}
QStringList MetaEditorPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Container") {
		result  << "ownedComment";
	}
	else if (element == "Explosion") {
		result  << "makeReusable" << "ownedComment" << "requireImmediateLinkage";
	}
	else if (element == "Inheritance") {
		result  << "ownedComment";
	}
	else if (element == "Listener") {
		result  << "class" << "file";
	}
	else if (element == "MetaEditorDiagramNode") {
		result  << "displayedName" << "isView" << "language" << "nodeName";
	}
	else if (element == "MetaEntity_Attribute") {
		result  << "attributeType" << "defaultValue" << "displayedName";
	}
	else if (element == "MetaEntityAssociation") {
		result  << "beginName" << "beginType" << "endName" << "endType";
	}
	else if (element == "MetaEntityConnection") {
		result  << "type";
	}
	else if (element == "MetaEntityContextMenuField") {
	}
	else if (element == "MetaEntityEdge") {
		result  << "displayedName" << "fromPorts" << "labelText" << "labelType" << "lineType" << "shape"
		 << "toPorts";
	}
	else if (element == "MetaEntityEnum") {
		result  << "displayedName";
	}
	else if (element == "MetaEntityImport") {
		result  << "as" << "displayedName" << "importedFrom";
	}
	else if (element == "MetaEntityNode") {
		result  << "createChildrenFromMenu" << "description" << "displayedName" << "gesture" << "isAction"
		 << "isResizeable" << "isView" << "language" << "path" << "shape";
	}
	else if (element == "MetaEntityPort") {
	}
	else if (element == "MetaEntityPossibleEdge") {
		result  << "beginName" << "directed" << "endName";
	}
	else if (element == "MetaEntityPropertiesAsContainer") {
		result  << "banChildrenMove" << "childrenForestallingSize" << "forestallingSize" << "maximizeChildren"
		 << "minimizeToChildren" << "sortContainer";
	}
	else if (element == "MetaEntityUsage") {
		result  << "type";
	}
	else if (element == "MetaEntityValue") {
		result  << "valueName";
	}
	else if (element == "MetamodelDiagram") {
		result  << "displayedName" << "include" << "name of the directory" << "path to QReal Source Files"
		;
	}
	else if (element == "PackageDiagram") {
		result  << "isView" << "language";
	}
	return result;
}

QStringList MetaEditorPlugin::getPortTypes(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Listener") {
	}
	else if (element == "MetaEditorDiagramNode") {
		result << "NonTyped";
	}
	else if (element == "MetaEntity_Attribute") {
	}
	else if (element == "MetaEntityAssociation") {
	}
	else if (element == "MetaEntityConnection") {
	}
	else if (element == "MetaEntityContextMenuField") {
	}
	else if (element == "MetaEntityEdge") {
		result << "NonTyped";
	}
	else if (element == "MetaEntityEnum") {
		result << "NonTyped";
	}
	else if (element == "MetaEntityImport") {
		result << "NonTyped";
	}
	else if (element == "MetaEntityNode") {
		result << "NonTyped";
	}
	else if (element == "MetaEntityPort") {
	}
	else if (element == "MetaEntityPossibleEdge") {
	}
	else if (element == "MetaEntityPropertiesAsContainer") {
	}
	else if (element == "MetaEntityUsage") {
	}
	else if (element == "MetaEntityValue") {
	}
	else if (element == "MetamodelDiagram") {
		result << "NonTyped";
	}
	else if (element == "PackageDiagram") {
		result << "NonTyped";
	}
	return result;
}

QStringList MetaEditorPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Container") {
	}
	else if (element == "Explosion") {
	}
	else if (element == "Inheritance") {
	}
	else if (element == "Listener") {
	}
	else if (element == "MetaEditorDiagramNode") {
	}
	else if (element == "MetaEntity_Attribute") {
	}
	else if (element == "MetaEntityAssociation") {
	}
	else if (element == "MetaEntityConnection") {
	}
	else if (element == "MetaEntityContextMenuField") {
	}
	else if (element == "MetaEntityEdge") {
		result  << "fromPorts" << "toPorts";
	}
	else if (element == "MetaEntityEnum") {
	}
	else if (element == "MetaEntityImport") {
	}
	else if (element == "MetaEntityNode") {
	}
	else if (element == "MetaEntityPort") {
	}
	else if (element == "MetaEntityPossibleEdge") {
	}
	else if (element == "MetaEntityPropertiesAsContainer") {
	}
	else if (element == "MetaEntityUsage") {
	}
	else if (element == "MetaEntityValue") {
	}
	else if (element == "MetamodelDiagram") {
	}
	else if (element == "PackageDiagram") {
	}
	return result;
}

QStringList MetaEditorPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "MetaEditorDiagramNode") {
		result << "MetaEntityNode" << "MetaEntityEdge" << "MetaEntityPort" << "MetaEntityEnum" << "MetaEntityImport" << "Inheritance" ;
	}
	else if (element == "MetaEntityEdge") {
		result << "MetaEntity_Attribute" << "MetaEntityAssociation" << "Inheritance" << "Importation" ;
	}
	else if (element == "MetaEntityEnum") {
		result << "MetaEntityValue" ;
	}
	else if (element == "MetaEntityNode") {
		result << "MetaEntity_Attribute" << "MetaEntityConnection" << "MetaEntityUsage" << "Inheritance" << "MetaEntityPossibleEdge" << "MetaEntityPropertiesAsContainer" ;
	}
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > MetaEditorPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	Q_UNUSED(element);
	return result;
}

//(-1) means "edge", (+1) means "node"
int MetaEditorPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "Container")
		return -1;
	else if (element == "Explosion")
		return -1;
	else if (element == "Inheritance")
		return -1;
	else if (element == "Listener")
		return 1;
	else if (element == "MetaEditorDiagramNode")
		return 1;
	else if (element == "MetaEntity_Attribute")
		return 1;
	else if (element == "MetaEntityAssociation")
		return 1;
	else if (element == "MetaEntityConnection")
		return 1;
	else if (element == "MetaEntityContextMenuField")
		return 1;
	else if (element == "MetaEntityEdge")
		return 1;
	else if (element == "MetaEntityEnum")
		return 1;
	else if (element == "MetaEntityImport")
		return 1;
	else if (element == "MetaEntityNode")
		return 1;
	else if (element == "MetaEntityPort")
		return 1;
	else if (element == "MetaEntityPossibleEdge")
		return 1;
	else if (element == "MetaEntityPropertiesAsContainer")
		return 1;
	else if (element == "MetaEntityUsage")
		return 1;
	else if (element == "MetaEntityValue")
		return 1;
	else if (element == "MetamodelDiagram")
		return 1;
	else if (element == "PackageDiagram")
		return 1;
	else if (element == "AssociationTypes")
		return 0;
	else if (element == "LabelTypes")
		return 0;
	else if (element == "LineTypes")
		return 0;
	else if (element == "LinkShapeType")
		return 0;
	return 0;
}
QString MetaEditorPlugin::getGroupsXML() const 
{
	return QString::fromUtf8("");
}

QStringList MetaEditorPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	if (name == "LinkShapeType")
		result << QString::fromUtf8("broken") << QString::fromUtf8("square") << QString::fromUtf8("curve");
	else if (name == "AssociationTypes")
		result << QString::fromUtf8("no_arrow") << QString::fromUtf8("open_arrow") << QString::fromUtf8("empty_arrow") << QString::fromUtf8("filled_arrow") << QString::fromUtf8("empty_rhomb") << QString::fromUtf8("filled_rhomb") << QString::fromUtf8("crossed_line") << QString::fromUtf8("empty_circle");
	else if (name == "LineTypes")
		result << QString::fromUtf8("solidLine") << QString::fromUtf8("dashLine") << QString::fromUtf8("dotLine");
	else if (name == "ParameterDirectionKind")
		result << QString::fromUtf8("in") << QString::fromUtf8("inout") << QString::fromUtf8("out") << QString::fromUtf8("return");
	else if (name == "AggregationKind")
		result << QString::fromUtf8("none") << QString::fromUtf8("shared") << QString::fromUtf8("composite");
	else if (name == "VisibilityKind")
		result << QString::fromUtf8("private") << QString::fromUtf8("protected") << QString::fromUtf8("public") << QString::fromUtf8("package");
	else if (name == "LabelTypes")
		result << QString::fromUtf8("Static text") << QString::fromUtf8("Dynamic text");
	else if (name == "Bool")
		result << QString::fromUtf8("false") << QString::fromUtf8("true");
	return result;
}

QString MetaEditorPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return mPropertyTypes[element][property];
}

QString MetaEditorPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return mPropertyDefault[element][property];
}

QList<qReal::ListenerInterface*> MetaEditorPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
