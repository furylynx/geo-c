/*
 * IOControllerLOC.cpp
 *
 *  Created on: 27.01.2015
 *      Author: John
 */

#include "IOControllerLOC.h"

using namespace Osp::Xml;

namespace geo
{

IOControllerLOC::IOControllerLOC()
{

}

IOControllerLOC::~IOControllerLOC()
{

}

void IOControllerLOC::Construct()
{

}

result IOControllerLOC::ParseLOC(Osp::Base::String path, Entry* outEntry)
{
	xmlDocPtr pDocument = null;
	xmlNodePtr pRoot = null;

	pDocument = xmlParseFile((const char*)path.GetPointer());
	pRoot = xmlDocGetRootElement(pDocument);

	xmlNodeSetPtr nodeset = xmlXPathEval((xmlChar*)"//waypoint//name", pRoot)->nodesetval;


	//snippet to work?!
//	xmlXPathObjectPtr
//		getnodeset (xmlDocPtr doc, xmlChar *xpath){
//
//		1xmlXPathContextPtr context;
//		xmlXPathObjectPtr result;
//
//		2context = xmlXPathNewContext(doc);
//		3result = xmlXPathEvalExpression(xpath, context);
//		4if(xmlXPathNodeSetIsEmpty(result->nodesetval)){
//			xmlXPathFreeObject(result);
//	                printf("No result\n");
//			return NULL;

	if (nodeset->nodeMax > 0)
	{
		xmlNodePtr node = nodeset->nodeTab[0];
		Osp::Base::String nameId;
		//TODO access attribute not content!
		Osp::Base::Utility::StringUtil::Utf8ToString((char*)node->content, &nameId);
		outEntry->SetNameId(nameId);
	}

//	for (pCurrentElement = pRoot->children; pCurrentElement; pCurrentElement = pCurrentElement->next)
//	{
//		String* countryName = new String;
//		xmlNodePtr pChildElement = null;
//		if (pCurrentElement->type == XML_ELEMENT_NODE)
//		{
//			// Get <country> element from <item> element
//			pChildElement = pCurrentElement->children->next;
//			if (pChildElement)
//			{
//				// Get content from XML_TEXT_NODE
//				Osp::Base::Utility::StringUtil::Utf8ToString((char*)
//													  pChildElement->children
//													  ->content, *countryName);
//				__pItemList->Add(*countryName);
//				AppLog("country : %S\n", (*countryName).GetPointer());
//			}
//		}
//	}

}

result IOControllerLOC::WriteToLOC(Osp::Base::String path, geo::Entry* entry)
{
    int err;
    xmlTextWriterPtr writer = xmlNewTextWriterFilename((const char*)Osp::Base::Utility::StringUtil::StringToUtf8N(path), 0);

    err = xmlTextWriterStartElement(writer, (xmlChar*)"loc");
    err = xmlTextWriterWriteAttribute(writer, (xmlChar*)"version", (xmlChar*)"1.0");
    err = xmlTextWriterWriteAttribute(writer, (xmlChar*)"src", (xmlChar*)"Groundspeak");

    err = xmlTextWriterStartElement(writer, (xmlChar*)"waypoint");

    err = xmlTextWriterStartElement(writer, (xmlChar*)"name");
    err = xmlTextWriterWriteAttribute(writer, (xmlChar*)"id", (xmlChar*) entry->NameId().GetPointer());

    //cdata segment
    std::stringstream sstrCDATA;
    sstrCDATA << entry->Title().GetPointer() << " by " << entry->Author().GetPointer();
    err = xmlTextWriterStartCDATA(writer);
    err = xmlTextWriterWriteCDATA(writer, (xmlChar*)sstrCDATA.str().c_str());
    err = xmlTextWriterEndCDATA(writer);

    err = xmlTextWriterEndElement(writer);

    err = xmlTextWriterStartElement(writer, (xmlChar*)"coord");

    std::stringstream sstrLat;
    sstrLat << entry->Latitude();
    err = xmlTextWriterWriteAttribute(writer, (xmlChar*)"lat", (xmlChar*) sstrLat.str().c_str());

    std::stringstream sstrLon;
    sstrLon << entry->Longitude();
    err = xmlTextWriterWriteAttribute(writer, (xmlChar*)"lon", (xmlChar*) sstrLon.str().c_str());

    err = xmlTextWriterEndElement(writer);
    err = xmlTextWriterStartElement(writer, (xmlChar*)"type");
    err = xmlTextWriterWriteRaw(writer, (xmlChar*)entry->Type().GetPointer());
    err = xmlTextWriterEndElement(writer);

    err = xmlTextWriterStartElement(writer, (xmlChar*)"link");
    err = xmlTextWriterWriteAttribute(writer, (xmlChar*)"text", (xmlChar*)"Cache Details");
    err = xmlTextWriterWriteRaw(writer, (xmlChar*)entry->Url().GetPointer());
    err = xmlTextWriterEndElement(writer);

    err = xmlTextWriterEndElement(writer);
    err = xmlTextWriterEndElement(writer);

    err = xmlTextWriterEndDocument(writer);

    xmlFreeTextWriter(writer);

}

}//namespace geo
