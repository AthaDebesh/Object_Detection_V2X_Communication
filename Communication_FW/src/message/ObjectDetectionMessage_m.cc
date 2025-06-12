//
// Generated file, do not edit! Created by opp_msgtool 6.1 from message/ObjectDetectionMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "ObjectDetectionMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace veins {

Register_Class(ObjectDetectionMessage)

ObjectDetectionMessage::ObjectDetectionMessage(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

ObjectDetectionMessage::ObjectDetectionMessage(const ObjectDetectionMessage& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

ObjectDetectionMessage::~ObjectDetectionMessage()
{
}

ObjectDetectionMessage& ObjectDetectionMessage::operator=(const ObjectDetectionMessage& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void ObjectDetectionMessage::copy(const ObjectDetectionMessage& other)
{
    this->vehicleId = other.vehicleId;
    this->detectionTime = other.detectionTime;
    this->position = other.position;
    this->objectDetected = other.objectDetected;
    this->distanceToIntersection = other.distanceToIntersection;
}

void ObjectDetectionMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->vehicleId);
    doParsimPacking(b,this->detectionTime);
    doParsimPacking(b,this->position);
    doParsimPacking(b,this->objectDetected);
    doParsimPacking(b,this->distanceToIntersection);
}

void ObjectDetectionMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->vehicleId);
    doParsimUnpacking(b,this->detectionTime);
    doParsimUnpacking(b,this->position);
    doParsimUnpacking(b,this->objectDetected);
    doParsimUnpacking(b,this->distanceToIntersection);
}

const char * ObjectDetectionMessage::getVehicleId() const
{
    return this->vehicleId.c_str();
}

void ObjectDetectionMessage::setVehicleId(const char * vehicleId)
{
    this->vehicleId = vehicleId;
}

double ObjectDetectionMessage::getDetectionTime() const
{
    return this->detectionTime;
}

void ObjectDetectionMessage::setDetectionTime(double detectionTime)
{
    this->detectionTime = detectionTime;
}

const Coord& ObjectDetectionMessage::getPosition() const
{
    return this->position;
}

void ObjectDetectionMessage::setPosition(const Coord& position)
{
    this->position = position;
}

bool ObjectDetectionMessage::getObjectDetected() const
{
    return this->objectDetected;
}

void ObjectDetectionMessage::setObjectDetected(bool objectDetected)
{
    this->objectDetected = objectDetected;
}

double ObjectDetectionMessage::getDistanceToIntersection() const
{
    return this->distanceToIntersection;
}

void ObjectDetectionMessage::setDistanceToIntersection(double distanceToIntersection)
{
    this->distanceToIntersection = distanceToIntersection;
}

class ObjectDetectionMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_vehicleId,
        FIELD_detectionTime,
        FIELD_position,
        FIELD_objectDetected,
        FIELD_distanceToIntersection,
    };
  public:
    ObjectDetectionMessageDescriptor();
    virtual ~ObjectDetectionMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ObjectDetectionMessageDescriptor)

ObjectDetectionMessageDescriptor::ObjectDetectionMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::ObjectDetectionMessage)), "veins::BaseFrame1609_4")
{
    propertyNames = nullptr;
}

ObjectDetectionMessageDescriptor::~ObjectDetectionMessageDescriptor()
{
    delete[] propertyNames;
}

bool ObjectDetectionMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ObjectDetectionMessage *>(obj)!=nullptr;
}

const char **ObjectDetectionMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ObjectDetectionMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ObjectDetectionMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int ObjectDetectionMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_vehicleId
        FD_ISEDITABLE,    // FIELD_detectionTime
        0,    // FIELD_position
        FD_ISEDITABLE,    // FIELD_objectDetected
        FD_ISEDITABLE,    // FIELD_distanceToIntersection
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *ObjectDetectionMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vehicleId",
        "detectionTime",
        "position",
        "objectDetected",
        "distanceToIntersection",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int ObjectDetectionMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "vehicleId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "detectionTime") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "position") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "objectDetected") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "distanceToIntersection") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *ObjectDetectionMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_vehicleId
        "double",    // FIELD_detectionTime
        "veins::Coord",    // FIELD_position
        "bool",    // FIELD_objectDetected
        "double",    // FIELD_distanceToIntersection
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **ObjectDetectionMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ObjectDetectionMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ObjectDetectionMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ObjectDetectionMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ObjectDetectionMessage'", field);
    }
}

const char *ObjectDetectionMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ObjectDetectionMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: return oppstring2string(pp->getVehicleId());
        case FIELD_detectionTime: return double2string(pp->getDetectionTime());
        case FIELD_position: return "";
        case FIELD_objectDetected: return bool2string(pp->getObjectDetected());
        case FIELD_distanceToIntersection: return double2string(pp->getDistanceToIntersection());
        default: return "";
    }
}

void ObjectDetectionMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: pp->setVehicleId((value)); break;
        case FIELD_detectionTime: pp->setDetectionTime(string2double(value)); break;
        case FIELD_objectDetected: pp->setObjectDetected(string2bool(value)); break;
        case FIELD_distanceToIntersection: pp->setDistanceToIntersection(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ObjectDetectionMessage'", field);
    }
}

omnetpp::cValue ObjectDetectionMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: return pp->getVehicleId();
        case FIELD_detectionTime: return pp->getDetectionTime();
        case FIELD_position: return omnetpp::toAnyPtr(&pp->getPosition()); break;
        case FIELD_objectDetected: return pp->getObjectDetected();
        case FIELD_distanceToIntersection: return pp->getDistanceToIntersection();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ObjectDetectionMessage' as cValue -- field index out of range?", field);
    }
}

void ObjectDetectionMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: pp->setVehicleId(value.stringValue()); break;
        case FIELD_detectionTime: pp->setDetectionTime(value.doubleValue()); break;
        case FIELD_objectDetected: pp->setObjectDetected(value.boolValue()); break;
        case FIELD_distanceToIntersection: pp->setDistanceToIntersection(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ObjectDetectionMessage'", field);
    }
}

const char *ObjectDetectionMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ObjectDetectionMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        case FIELD_position: return omnetpp::toAnyPtr(&pp->getPosition()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ObjectDetectionMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ObjectDetectionMessage *pp = omnetpp::fromAnyPtr<ObjectDetectionMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ObjectDetectionMessage'", field);
    }
}

Register_Class(ImagePacketMessage)

ImagePacketMessage::ImagePacketMessage(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

ImagePacketMessage::ImagePacketMessage(const ImagePacketMessage& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

ImagePacketMessage::~ImagePacketMessage()
{
}

ImagePacketMessage& ImagePacketMessage::operator=(const ImagePacketMessage& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void ImagePacketMessage::copy(const ImagePacketMessage& other)
{
    this->originalSender = other.originalSender;
    this->packetNumber = other.packetNumber;
    this->totalPackets = other.totalPackets;
    this->imageDataChunk = other.imageDataChunk;
    this->checksum = other.checksum;
}

void ImagePacketMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->originalSender);
    doParsimPacking(b,this->packetNumber);
    doParsimPacking(b,this->totalPackets);
    doParsimPacking(b,this->imageDataChunk);
    doParsimPacking(b,this->checksum);
}

void ImagePacketMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->originalSender);
    doParsimUnpacking(b,this->packetNumber);
    doParsimUnpacking(b,this->totalPackets);
    doParsimUnpacking(b,this->imageDataChunk);
    doParsimUnpacking(b,this->checksum);
}

const char * ImagePacketMessage::getOriginalSender() const
{
    return this->originalSender.c_str();
}

void ImagePacketMessage::setOriginalSender(const char * originalSender)
{
    this->originalSender = originalSender;
}

int ImagePacketMessage::getPacketNumber() const
{
    return this->packetNumber;
}

void ImagePacketMessage::setPacketNumber(int packetNumber)
{
    this->packetNumber = packetNumber;
}

int ImagePacketMessage::getTotalPackets() const
{
    return this->totalPackets;
}

void ImagePacketMessage::setTotalPackets(int totalPackets)
{
    this->totalPackets = totalPackets;
}

const char * ImagePacketMessage::getImageDataChunk() const
{
    return this->imageDataChunk.c_str();
}

void ImagePacketMessage::setImageDataChunk(const char * imageDataChunk)
{
    this->imageDataChunk = imageDataChunk;
}

int ImagePacketMessage::getChecksum() const
{
    return this->checksum;
}

void ImagePacketMessage::setChecksum(int checksum)
{
    this->checksum = checksum;
}

class ImagePacketMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_originalSender,
        FIELD_packetNumber,
        FIELD_totalPackets,
        FIELD_imageDataChunk,
        FIELD_checksum,
    };
  public:
    ImagePacketMessageDescriptor();
    virtual ~ImagePacketMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ImagePacketMessageDescriptor)

ImagePacketMessageDescriptor::ImagePacketMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::ImagePacketMessage)), "veins::BaseFrame1609_4")
{
    propertyNames = nullptr;
}

ImagePacketMessageDescriptor::~ImagePacketMessageDescriptor()
{
    delete[] propertyNames;
}

bool ImagePacketMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ImagePacketMessage *>(obj)!=nullptr;
}

const char **ImagePacketMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ImagePacketMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ImagePacketMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int ImagePacketMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_originalSender
        FD_ISEDITABLE,    // FIELD_packetNumber
        FD_ISEDITABLE,    // FIELD_totalPackets
        FD_ISEDITABLE,    // FIELD_imageDataChunk
        FD_ISEDITABLE,    // FIELD_checksum
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *ImagePacketMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "originalSender",
        "packetNumber",
        "totalPackets",
        "imageDataChunk",
        "checksum",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int ImagePacketMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "originalSender") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "packetNumber") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "totalPackets") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "imageDataChunk") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "checksum") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *ImagePacketMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",    // FIELD_originalSender
        "int",    // FIELD_packetNumber
        "int",    // FIELD_totalPackets
        "string",    // FIELD_imageDataChunk
        "int",    // FIELD_checksum
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **ImagePacketMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ImagePacketMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ImagePacketMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ImagePacketMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ImagePacketMessage'", field);
    }
}

const char *ImagePacketMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ImagePacketMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        case FIELD_originalSender: return oppstring2string(pp->getOriginalSender());
        case FIELD_packetNumber: return long2string(pp->getPacketNumber());
        case FIELD_totalPackets: return long2string(pp->getTotalPackets());
        case FIELD_imageDataChunk: return oppstring2string(pp->getImageDataChunk());
        case FIELD_checksum: return long2string(pp->getChecksum());
        default: return "";
    }
}

void ImagePacketMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        case FIELD_originalSender: pp->setOriginalSender((value)); break;
        case FIELD_packetNumber: pp->setPacketNumber(string2long(value)); break;
        case FIELD_totalPackets: pp->setTotalPackets(string2long(value)); break;
        case FIELD_imageDataChunk: pp->setImageDataChunk((value)); break;
        case FIELD_checksum: pp->setChecksum(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ImagePacketMessage'", field);
    }
}

omnetpp::cValue ImagePacketMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        case FIELD_originalSender: return pp->getOriginalSender();
        case FIELD_packetNumber: return pp->getPacketNumber();
        case FIELD_totalPackets: return pp->getTotalPackets();
        case FIELD_imageDataChunk: return pp->getImageDataChunk();
        case FIELD_checksum: return pp->getChecksum();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ImagePacketMessage' as cValue -- field index out of range?", field);
    }
}

void ImagePacketMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        case FIELD_originalSender: pp->setOriginalSender(value.stringValue()); break;
        case FIELD_packetNumber: pp->setPacketNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_totalPackets: pp->setTotalPackets(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_imageDataChunk: pp->setImageDataChunk(value.stringValue()); break;
        case FIELD_checksum: pp->setChecksum(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ImagePacketMessage'", field);
    }
}

const char *ImagePacketMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ImagePacketMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ImagePacketMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ImagePacketMessage *pp = omnetpp::fromAnyPtr<ImagePacketMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ImagePacketMessage'", field);
    }
}

}  // namespace veins

namespace omnetpp {

}  // namespace omnetpp

