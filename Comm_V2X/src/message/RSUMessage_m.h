//
// Generated file, do not edit! Created by opp_msgtool 6.1 from message/RSUMessage.msg.
//

#ifndef __VEINS_RSUMESSAGE_M_H
#define __VEINS_RSUMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0601
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif


namespace veins {

class RSUMessage;

}  // namespace veins

// cplusplus {{
	#define DRAW 30
	#define AWARENESS 31
	#define EMERGENCY 32
// }}

#include "veins/modules/messages/BaseFrame1609_4_m.h" // import veins.modules.messages.BaseFrame1609_4


namespace veins {

/**
 * Class generated from <tt>message/RSUMessage.msg:25</tt> by opp_msgtool.
 * <pre>
 * packet RSUMessage extends BaseFrame1609_4
 * {
 *     //int source;
 *     int destination;
 *     int messageKind;
 *     simtime_t timestamp;
 *     // can add a field for storing the id of the relaying vehicle
 * }
 * </pre>
 */
class RSUMessage : public ::veins::BaseFrame1609_4
{
  protected:
    int destination = 0;
    int messageKind = 0;
    ::omnetpp::simtime_t timestamp = SIMTIME_ZERO;

  private:
    void copy(const RSUMessage& other);

  protected:
    bool operator==(const RSUMessage&) = delete;

  public:
    RSUMessage(const char *name=nullptr, short kind=0);
    RSUMessage(const RSUMessage& other);
    virtual ~RSUMessage();
    RSUMessage& operator=(const RSUMessage& other);
    virtual RSUMessage *dup() const override {return new RSUMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getDestination() const;
    virtual void setDestination(int destination);

    virtual int getMessageKind() const;
    virtual void setMessageKind(int messageKind);

    virtual ::omnetpp::simtime_t getTimestamp() const;
    virtual void setTimestamp(::omnetpp::simtime_t timestamp);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const RSUMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, RSUMessage& obj) {obj.parsimUnpack(b);}


}  // namespace veins


namespace omnetpp {

template<> inline veins::RSUMessage *fromAnyPtr(any_ptr ptr) { return check_and_cast<veins::RSUMessage*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __VEINS_RSUMESSAGE_M_H

