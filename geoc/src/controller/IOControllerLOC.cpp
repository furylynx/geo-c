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

result IOControllerLOC::ParseLOC(Osp::Base::String path, Entry* outEntry) const
{

	xmlDocPtr pDocument = xmlParseFile((const char*)path.GetPointer());
	xmlNodePtr pRoot = xmlDocGetRootElement(pDocument);
	xmlXPathContextPtr context = xmlXPathNewContext(pDocument);

	//search for name tag
	xmlXPathObjectPtr nameXPath = xmlXPathEval((xmlChar*)"//loc//waypoint//name", context);
	xmlNodeSetPtr nameNodeSet = nameXPath->nodesetval;

	if (nameNodeSet->nodeMax > 0)
	{
		xmlNodePtr node = nameNodeSet->nodeTab[0];

		//get the id
		xmlChar* value = xmlGetProp(node, (xmlChar*)"id");

		Osp::Base::String nameId;
		Osp::Base::Utility::StringUtil::Utf8ToString((const char*) (value), nameId);
		outEntry->SetNameId(nameId);

		xmlFree(value);

		if (node->children != NULL)
		{
			//TODO working?
			Osp::Base::String cdata;
			Osp::Base::Utility::StringUtil::Utf8ToString((const char*) (node->children->content), cdata);

			int indexOfBy;
			result indexOfResult = cdata.IndexOf("by", 0, indexOfBy);

			if (indexOfBy > 0)
			{
				Osp::Base::String title;
				Osp::Base::String author;
				cdata.SubString(0, indexOfBy, title);
				title.Trim();
				cdata.SubString(indexOfBy+2, author);
				author.Trim();

				outEntry->SetTitle(title);
				outEntry->SetAuthor(author);
			}
		}
	}

	xmlXPathFreeObject(nameXPath);


	//search for coord tag
	xmlXPathObjectPtr coordXPath = xmlXPathEval((xmlChar*)"//loc//waypoint//coord", context);
	xmlNodeSetPtr coordNodeSet = coordXPath->nodesetval;

	if (coordNodeSet->nodeMax > 0)
	{
		xmlNodePtr node = coordNodeSet->nodeTab[0];

		//parse latitude and longitude
		xmlChar* valueLat = xmlGetProp(node, (xmlChar*)"lat");
		xmlChar* valueLon = xmlGetProp(node, (xmlChar*)"lon");

		float lat = std::atof((const char*) valueLat);
		float lon = std::atof((const char*) valueLon);

		outEntry->SetLatitude(lat);
		outEntry->SetLongitude(lon);

		xmlFree(valueLat);
		xmlFree(valueLon);
	}

	xmlXPathFreeObject(coordXPath);


	//search for type tag
	xmlXPathObjectPtr typeXPath = xmlXPathEval((xmlChar*)"//loc//waypoint//type", context);
	xmlNodeSetPtr typeNodeSet = coordXPath->nodesetval;

	if (typeNodeSet->nodeMax > 0)
	{
		xmlNodePtr node = typeNodeSet->nodeTab[0];

		//get the type
		Osp::Base::String type;
		Osp::Base::Utility::StringUtil::Utf8ToString((const char*) (node->content), type);
		outEntry->SetType(type);
	}

	xmlXPathFreeObject(typeXPath);

	//search for type tag
	xmlXPathObjectPtr urlXPath = xmlXPathEval((xmlChar*)"//loc//waypoint//link", context);
	xmlNodeSetPtr urlNodeSet = urlXPath->nodesetval;

	if (urlNodeSet->nodeMax > 0)
	{
		xmlNodePtr node = urlNodeSet->nodeTab[0];

		//get the url
		Osp::Base::String url;
		Osp::Base::Utility::StringUtil::Utf8ToString((const char*) (node->content), url);
		outEntry->SetUrl(url);

	}

	xmlXPathFreeObject(urlXPath);



	//free everything
	xmlXPathFreeContext(context);
	//TODO free document, rootNode?

}

result IOControllerLOC::WriteToLOC(Osp::Base::String path, geo::Entry* entry) const
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


result IOControllerLOC::ParseGPX(Osp::Base::String path, geo::Entry* outEntry) const
{
	//TODO parse gpx file

	return E_SUCCESS;
}

result IOControllerLOC::WriteToGPX(Osp::Base::String path, geo::Entry* entry) const
{
	//TODO write gpx file

	return E_SUCCESS;
}

}//namespace geo
