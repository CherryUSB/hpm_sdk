/* constants.h */

#ifndef CONSTANTS_H
#define CONSTANTS_H

/* implementation specific constants */
#define MANUFACTURER_ID \
    "PTPd;1.0.1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#ifndef DEFAULT_SYNC_INTERVAL
#define DEFAULT_SYNC_INTERVAL        0
#endif

#ifndef DEFAULT_UTC_OFFSET
#define DEFAULT_UTC_OFFSET           0
#endif

#ifndef DEFAULT_CLOCK_VARIANCE
#define DEFAULT_CLOCK_VARIANCE       (-4000)
#endif

#ifndef DEFAULT_CLOCK_STRATUM
#define DEFAULT_CLOCK_STRATUM        4
#endif

#ifndef DEFAULT_INBOUND_LATENCY
#define DEFAULT_INBOUND_LATENCY      0       /* in nsec */
#endif

#ifndef DEFAULT_OUTBOUND_LATENCY
#define DEFAULT_OUTBOUND_LATENCY     0       /* in nsec */
#endif

#ifndef DEFAULT_NO_RESET_CLOCK
#define DEFAULT_NO_RESET_CLOCK       FALSE
#endif

#ifndef DEFAULT_AP
#define DEFAULT_AP                   2       /* 10 */
#endif

#ifndef DEFAULT_AI
#define DEFAULT_AI                   15      /* 1000 */
#endif

#ifndef DEFAULT_DELAY_S
#define DEFAULT_DELAY_S              6
#endif

#ifndef DEFAULT_OFFSET_S
#define DEFAULT_OFFSET_S             1
#endif

#ifndef DEFUALT_MAX_FOREIGN_RECORDS
#define DEFUALT_MAX_FOREIGN_RECORDS  5
#endif

#ifndef DEFAULT_CALIBRATED_OFFSET_NS
#define DEFAULT_CALIBRATED_OFFSET_NS    10000   /* offset from master < 10us -> calibrated */
#endif

#ifndef DEFAULT_UNCALIBRATED_OFFSET_NS
#define DEFAULT_UNCALIBRATED_OFFSET_NS  1000000 /* offset from master > 1000us -> uncalibrated */
#endif


/* features, only change to reflect changes in implementation */
#ifndef CLOCK_FOLLOWUP
#define CLOCK_FOLLOWUP    TRUE
#endif

#ifndef INITIALIZABLE
#define INITIALIZABLE     TRUE
#endif

#ifndef BURST_ENABLED
#define BURST_ENABLED     FALSE
#endif

#ifndef EXTERNAL_TIMING
#define EXTERNAL_TIMING   FALSE
#endif

#ifndef BOUNDARY_CLOCK
#define BOUNDARY_CLOCK    FALSE
#endif

#ifndef NUMBER_PORTS
#define NUMBER_PORTS      1
#endif

#ifndef VERSION_PTP
#define VERSION_PTP       1
#endif

#ifndef VERSION_NETWORK
#define VERSION_NETWORK   1
#endif

#ifndef SLAVE_ONLY
#define SLAVE_ONLY         FALSE
#endif

/* spec defined constants  */
#define DEFAULT_PTP_DOMAIN_NAME      "_DFLT\0\0\0\0\0\0\0\0\0\0\0"
#define ALTERNATE_PTP_DOMAIN1_NAME   "_ALT1\0\0\0\0\0\0\0\0\0\0\0"
#define ALTERNATE_PTP_DOMAIN2_NAME   "_ALT2\0\0\0\0\0\0\0\0\0\0\0"
#define ALTERNATE_PTP_DOMAIN3_NAME   "_ALT3\0\0\0\0\0\0\0\0\0\0\0"

#define IDENTIFIER_ATOM   "ATOM"
#define IDENTIFIER_GPS    "GPS\0"
#define IDENTIFIER_NTP    "NTP\0"
#define IDENTIFIER_HAND   "HAND"
#define IDENTIFIER_INIT   "INIT"
#define IDENTIFIER_DFLT   "DFLT"

/* ptp constants */
#define PTP_UUID_LENGTH                     6
#define PTP_CODE_STRING_LENGTH              4
#define PTP_SUBDOMAIN_NAME_LENGTH           16
#define PTP_MAX_MANAGEMENT_PAYLOAD_SIZE     90
/* no support for intervals less than one */
#define PTP_SYNC_INTERVAL_TIMEOUT(x)        (pow2ms((x)<0?1:(x)))
#define PTP_SYNC_RECEIPT_TIMEOUT(x)         (10*(pow2ms((x)<0?0:(x))))
#define PTP_DELAY_REQ_INTERVAL              30
#define PTP_FOREIGN_MASTER_THRESHOLD        2
#define PTP_FOREIGN_MASTER_TIME_WINDOW(x)   (4*(pow2ms((x)<0?0:(x))))
#define PTP_RANDOMIZING_SLOTS               18
#define PTP_LOG_VARIANCE_THRESHOLD          256
#define PTP_LOG_VARIANCE_HYSTERESIS         128
/* used in spec but not named */
#define MANUFACTURER_ID_LENGTH              48

/* ptp data enums */
enum
{
    PTP_CLOSED = 0,  PTP_ETHER,  PTP_FFBUS = 4,
    PTP_PROFIBUS,  PTP_LON,  PTP_DNET,
    PTP_SDS,  PTP_CONTROLNET,  PTP_CANOPEN,
    PTP_IEEE1394 = 243,  PTP_IEEE802_11A,  PTP_IEEE_WIRELESS,
    PTP_INFINIBAND,  PTP_BLUETOOTH,  PTP_IEEE802_15_1,
    PTP_IEEE1451_2,  PTP_IEEE1451_5,  PTP_USB,
    PTP_ISA,  PTP_PCI,  PTP_VXI,  PTP_DEFAULT
};

enum
{
    PTP_INITIALIZING = 0,  PTP_FAULTY,  PTP_DISABLED,
    PTP_LISTENING,  PTP_PRE_MASTER,  PTP_MASTER,
    PTP_PASSIVE,  PTP_UNCALIBRATED,  PTP_SLAVE
};

enum
{
    PTP_SYNC_MESSAGE = 0,  PTP_DELAY_REQ_MESSAGE,  PTP_FOLLOWUP_MESSAGE,
    PTP_DELAY_RESP_MESSAGE,  PTP_MANAGEMENT_MESSAGE,
    PTP_SYNC_MESSAGE_BURST, PTP_DELAY_REQ_MESSAGE_BURST
};

enum
{
    PTP_LI_61 = 0, PTP_LI_59, PTP_BOUNDARY_CLOCK,
    PTP_ASSIST, PTP_EXT_SYNC, PARENT_STATS, PTP_SYNC_BURST
};

enum
{
    PTP_MM_NULL = 0,  PTP_MM_OBTAIN_IDENTITY,  PTP_MM_CLOCK_IDENTITY,
    PTP_MM_INITIALIZE_CLOCK,  PTP_MM_SET_SUBDOMAIN,
    PTP_MM_CLEAR_DESIGNATED_PREFERRED_MASTER,
    PTP_MM_SET_DESIGNATED_PREFERRED_MASTER,
    PTP_MM_GET_DEFAULT_DATA_SET,  PTP_MM_DEFAULT_DATA_SET,
    PTP_MM_UPDATE_DEFAULT_DATA_SET,  PTP_MM_GET_CURRENT_DATA_SET,
    PTP_MM_CURRENT_DATA_SET,  PTP_MM_GET_PARENT_DATA_SET,
    PTP_MM_PARENT_DATA_SET,  PTP_MM_GET_PORT_DATA_SET,
    PTP_MM_PORT_DATA_SET,  PTP_MM_GET_GLOBAL_TIME_DATA_SET,
    PTP_MM_GLOBAL_TIME_DATA_SET,  PTP_MM_UPDATE_GLOBAL_TIME_PROPERTIES,
    PTP_MM_GOTO_FAULTY_STATE,  PTP_MM_GET_FOREIGN_DATA_SET,
    PTP_MM_FOREIGN_DATA_SET,  PTP_MM_SET_SYNC_INTERVAL,
    PTP_MM_DISABLE_PORT,  PTP_MM_ENABLE_PORT,
    PTP_MM_DISABLE_BURST,  PTP_MM_ENABLE_BURST,  PTP_MM_SET_TIME
};

/* enum used by this implementation */
enum
{
    SYNC_RECEIPT_TIMER = 0, SYNC_INTERVAL_TIMER, QUALIFICATION_TIMER,
    TIMER_ARRAY_SIZE  /* these two are non-spec */
};

/* events */
enum
{
    POWERUP                         = 0x0001,
    INITIALIZE                      = 0x0002,
    DESIGNATED_ENABLED              = 0x0004,
    DESIGNATED_DISABLED             = 0x0008,
    FAULT_CLEARED                   = 0x0010,
    FAULT_DETECTED                  = 0x0020,
    STATE_DECISION_EVENT            = 0x0040,
    QUALIFICATION_TIMEOUT_EXPIRES   = 0x0080,
    ANNOUNCE_RECEIPT_TIMEOUT_EXPIRES  = 0x0100,
    SYNCHRONIZATION_FAULT           = 0x0200,
    MASTER_CLOCK_SELECTED           = 0x0400,
    /* non spec */
    MASTER_CLOCK_CHANGED            = 0x0800,
};


#endif
