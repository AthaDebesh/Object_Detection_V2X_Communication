//
// Generated file, do not edit! Created by opp_msgtool 6.1 from message/NumVehicleMsg.msg.
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
#include "NumVehicleMsg_m.h"

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

Register_Class(NumVehicleMsg)

NumVehicleMsg::NumVehicleMsg(const char *name, short kind) : ::veins::BaseFrame1609_4(name, kind)
{
}

NumVehicleMsg::NumVehicleMsg(const NumVehicleMsg& other) : ::veins::BaseFrame1609_4(other)
{
    copy(other);
}

NumVehicleMsg::~NumVehicleMsg()
{
}

NumVehicleMsg& NumVehicleMsg::operator=(const NumVehicleMsg& other)
{
    if (this == &other) return *this;
    ::veins::BaseFrame1609_4::operator=(other);
    copy(other);
    return *this;
}

void NumVehicleMsg::copy(const NumVehicleMsg& other)
{
    this->senderPos = other.senderPos;
    this->numVehicles = other.numVehicles;
    this->timeStampP = other.timeStampP;
    this->senderAddress = other.senderAddress;
}

void NumVehicleMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::veins::BaseFrame1609_4::parsimPack(b);
    doParsimPacking(b,this->senderPos);
    doParsimPacking(b,this->numVehicles);
    doParsimPacking(b,this->timeStampP);
    doParsimPacking(b,this->senderAddress);
}

void NumVehicleMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::veins::BaseFrame1609_4::parsimUnpack(b);
    doParsimUnpacking(b,this->senderPos);
    doParsimUnpacking(b,this->numVehicles);
    doParsimUnpacking(b,this->timeStampP);
    doParsimUnpacking(b,this->senderAddress);
}

const Coord& NumVehicleMsg::getSenderPos() const
{
    return this->senderPos;
}

void NumVehicleMsg::setSenderPos(const Coord& senderPos)
{
    this->senderPos = senderPos;
}

int NumVehicleMsg::getNumVehicles() const
{
    return this->numVehicles;
}

void NumVehicleMsg::setNumVehicles(int numVehicles)
{
    this->numVehicles = numVehicles;
}

::omnetpp::simtime_t NumVehicleMsg::getTimeStampP() const
{
    return this->timeStampP;
}

void NumVehicleMsg::setTimeStampP(::omnetpp::simtime_t timeStampP)
{
    this->timeStampP = timeStampP;
}

const LAddress::L2Type& NumVehicleMsg::getSenderAddress() const
{
    return this->senderAddress;
}

void NumVehicleMsg::setSenderAddress(const LAddress::L2Type& senderAddress)
{
    this->senderAddress = senderAddress;
}

class NumVehicleMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_senderPos,
        FIELD_numVehicles,
        FIELD_timeStampP,
        FIELD_senderAddress,
    };
  public:
    NumVehicleMsgDescriptor();
    virtual ~NumVehicleMsgDescriptor();

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

Register_ClassDescriptor(NumVehicleMsgDescriptor)

NumVehicleMsgDescriptor::NumVehicleMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(veins::NumVehicleMsg)), "veins::BaseFrame1609_4")
{
    propertyNames = nullptr;
}

NumVehicleMsgDescriptor::~NumVehicleMsgDescriptor()
{
    delete[] propertyNames;
}

bool NumVehicleMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NumVehicleMsg *>(obj)!=nullptr;
}

const char **NumVehicleMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *NumVehicleMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int NumVehicleMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int NumVehicleMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_senderPos
        FD_ISEDITABLE,    // FIELD_numVehicles
        FD_ISEDITABLE,    // FIELD_timeStampP
        0,    // FIELD_senderAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *NumVehicleMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "senderPos",
        "numVehicles",
        "timeStampP",
        "senderAddress",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int NumVehicleMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "senderPos") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "numVehicles") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "timeStampP") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "senderAddress") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *NumVehicleMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "veins::Coord",    // FIELD_senderPos
        "int",    // FIELD_numVehicles
        "omnetpp::simtime_t",    // FIELD_timeStampP
        "veins::LAddress::L2Type",    // FIELD_senderAddress
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **NumVehicleMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *NumVehicleMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int NumVehicleMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void NumVehicleMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'NumVehicleMsg'", field);
    }
}

const char *NumVehicleMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NumVehicleMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        case FIELD_senderPos: return "";
        case FIELD_numVehicles: return long2string(pp->getNumVehicles());
        case FIELD_timeStampP: return simtime2string(pp->getTimeStampP());
        case FIELD_senderAddress: return "";
        default: return "";
    }
}

void NumVehicleMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        case FIELD_numVehicles: pp->setNumVehicles(string2long(value)); break;
        case FIELD_timeStampP: pp->setTimeStampP(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NumVehicleMsg'", field);
    }
}

omnetpp::cValue NumVehicleMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        case FIELD_senderPos: return omnetpp::toAnyPtr(&pp->getSenderPos()); break;
        case FIELD_numVehicles: return pp->getNumVehicles();
        case FIELD_timeStampP: return pp->getTimeStampP().dbl();
        case FIELD_senderAddress: return omnetpp::toAnyPtr(&pp->getSenderAddress()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'NumVehicleMsg' as cValue -- field index out of range?", field);
    }
}

void NumVehicleMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        case FIELD_numVehicles: pp->setNumVehicles(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_timeStampP: pp->setTimeStampP(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NumVehicleMsg'", field);
    }
}

const char *NumVehicleMsgDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr NumVehicleMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        case FIELD_senderPos: return omnetpp::toAnyPtr(&pp->getSenderPos()); break;
        case FIELD_senderAddress: return omnetpp::toAnyPtr(&pp->getSenderAddress()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void NumVehicleMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    NumVehicleMsg *pp = omnetpp::fromAnyPtr<NumVehicleMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'NumVehicleMsg'", field);
    }
}

}  // namespace veins

namespace omnetpp {

}  // namespace omnetpp

