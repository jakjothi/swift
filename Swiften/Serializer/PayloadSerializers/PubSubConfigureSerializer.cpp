/*
 * Copyright (c) 2013-2016 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma clang diagnostic ignored "-Wunused-private-field"

#include <Swiften/Serializer/PayloadSerializers/PubSubConfigureSerializer.h>
#include <Swiften/Serializer/XML/XMLElement.h>
#include <memory>

#include <Swiften/Serializer/PayloadSerializerCollection.h>
#include <Swiften/Serializer/PayloadSerializers/FormSerializer.h>
#include <Swiften/Serializer/XML/XMLRawTextNode.h>

using namespace Swift;

PubSubConfigureSerializer::PubSubConfigureSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubConfigureSerializer::~PubSubConfigureSerializer() {
}

std::string PubSubConfigureSerializer::serializePayload(std::shared_ptr<PubSubConfigure> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("configure", "http://jabber.org/protocol/pubsub");
    element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    return element.serialize();
}


