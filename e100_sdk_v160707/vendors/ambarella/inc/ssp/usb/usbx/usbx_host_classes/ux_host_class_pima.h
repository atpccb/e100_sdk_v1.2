/**************************************************************************/
/*                                                                        */
/*            Copyright (c) 1996-2012 by Express Logic Inc.               */
/*                                                                        */
/*  This software is copyrighted by and is the sole property of Express   */
/*  Logic, Inc.  All rights, title, ownership, or other interests         */
/*  in the software remain the property of Express Logic, Inc.  This      */
/*  software may only be used in accordance with the corresponding        */
/*  license agreement.  Any unauthorized use, duplication, transmission,  */
/*  distribution, or disclosure of this software is expressly forbidden.  */
/*                                                                        */
/*  This Copyright notice may not be removed or modified without prior    */
/*  written consent of Express Logic, Inc.                                */
/*                                                                        */
/*  Express Logic, Inc. reserves the right to modify this software        */
/*  without notice.                                                       */
/*                                                                        */
/*  Express Logic, Inc.                     info@expresslogic.com         */
/*  11423 West Bernardo Court               http://www.expresslogic.com   */
/*  San Diego, CA  92127                                                  */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** USBX Component                                                        */
/**                                                                       */
/**   PIMA Class                                                          */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/**************************************************************************/
/*                                                                        */
/*  COMPONENT DEFINITION                                   RELEASE        */
/*                                                                        */
/*    ux_host_class_cdc_acm.h                             PORTABLE C      */
/*                                                           5.6          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Thierry Giron, Express Logic Inc.                                   */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This file contains all the header and extern functions used by the  */
/*    USBX PIMA class.                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  07-04-2008     TCRG                     Initial Version 5.1           */
/*  11-11-2008     TCRG                     Modified comment(s),          */
/*                                            resulting in version 5.2    */
/*  07-10-2009     TCRG                     Modified comment(s), and      */
/*                                            added trace logic,          */
/*                                            resulting in version 5.3    */
/*  06-13-2010     TCRG                     Modified comment(s),          */
/*                                            resulting in version 5.4    */
/*  09-01-2011     TCRG                     Modified comment(s),          */
/*                                            resulting in version 5.5    */
/*  10-10-2012     TCRG                     Modified comment(s),          */
/*                                            resulting in version 5.6    */
/*                                                                        */
/**************************************************************************/

#ifndef UX_HOST_CLASS_PIMA_H
#define UX_HOST_CLASS_PIMA_H

/* Define PIMA Class constants.  */

#define UX_HOST_CLASS_PIMA_CLASS_TRANSFER_TIMEOUT               300000
#define UX_HOST_CLASS_PIMA_CLASS                                0x06
#define UX_HOST_CLASS_PIMA_SUBCLASS                             0X01
#define UX_HOST_CLASS_PIMA_PROTOCOL                             0X01
#define UX_HOST_CLASS_PIMA_CS_INTERFACE                         0x24
#define UX_HOST_CLASS_PIMA_MAGIC_NUMBER                         0x50494D41
#define UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH                   256
#define UX_HOST_CLASS_PIMA_ARRAY_MAX_LENGTH                     256
#define UX_HOST_CLASS_PIMA_DATE_TIME_STRING_MAX_LENGTH          64
#define UX_HOST_CLASS_PIMA_MAX_STORAGE_IDS                      64
#define UX_HOST_CLASS_PIMA_STORAGE_IDS_LENGTH                   (UX_HOST_CLASS_PIMA_MAX_STORAGE_IDS * sizeof(ULONG))
#define UX_HOST_CLASS_PIMA_MAX_PAYLOAD                          1024
#define UX_HOST_CLASS_PIMA_ZLP_NONE                             0
#define UX_HOST_CLASS_PIMA_ZLP_IN                               1
#define UX_HOST_CLASS_PIMA_ZLP_OUT                              2

/* Define PIMA data phases.  */

#define UX_HOST_CLASS_PIMA_DATA_PHASE_NONE                      0
#define UX_HOST_CLASS_PIMA_DATA_PHASE_IN                        1
#define UX_HOST_CLASS_PIMA_DATA_PHASE_OUT                       2

/* Define PIMA session states.  */

#define UX_HOST_CLASS_PIMA_SESSION_STATE_CLOSED                 0
#define UX_HOST_CLASS_PIMA_SESSION_STATE_OPENED                 1

/* Define PIMA object and thumb states.  */

#define UX_HOST_CLASS_PIMA_OBJECT_STATE_CLOSED                  0
#define UX_HOST_CLASS_PIMA_OBJECT_STATE_OPENED                  1

/* Define PIMA object and thumb transfer status.  */

#define UX_HOST_CLASS_PIMA_OBJECT_TRANSFER_STATUS_INACTIVE      0
#define UX_HOST_CLASS_PIMA_OBJECT_TRANSFER_STATUS_ACTIVE        1
#define UX_HOST_CLASS_PIMA_OBJECT_TRANSFER_STATUS_COMPLETED     2
#define UX_HOST_CLASS_PIMA_OBJECT_TRANSFER_STATUS_ABORTED       3

/* Define PIMA Cancel Request equivalences.  */

#define UX_HOST_CLASS_PIMA_REQUEST_CANCEL_COMMAND               0x64
#define UX_HOST_CLASS_PIMA_REQUEST_CANCEL_DATA_LENGTH           0x06
#define UX_HOST_CLASS_PIMA_REQUEST_CANCEL_CODE                  0x04001
#define UX_HOST_CLASS_PIMA_REQUEST_CANCEL_OFFSET_CODE           0x00
#define UX_HOST_CLASS_PIMA_REQUEST_CANCEL_OFFSET_TRANSACTION_ID 0x02

/* Define PIMA Reset Request equivalences.  */

#define UX_HOST_CLASS_PIMA_REQUEST_RESET_DEVICE                 0x66

/* Define PIMA Status Request equivalences.  */

#define UX_HOST_CLASS_PIMA_REQUEST_STATUS_COMMAND               0x67
#define UX_HOST_CLASS_PIMA_REQUEST_STATUS_DATA_LENGTH           0x40
#define UX_HOST_CLASS_PIMA_REQUEST_STATUS_OFFSET_LENGTH         0x00
#define UX_HOST_CLASS_PIMA_REQUEST_STATUS_OFFSET_CODE           0x02
#define UX_HOST_CLASS_PIMA_REQUEST_STATUS_COMMAND_COUNTER       16
#define UX_HOST_CLASS_PIMA_REQUEST_STATUS_COMMAND_DELAY         (1 * UX_PERIODIC_RATE)

/* Define PIMA command container type.  */

#define UX_HOST_CLASS_PIMA_CT_UNDEFINED                         0x00
#define UX_HOST_CLASS_PIMA_CT_COMMAND_BLOCK                     0x01
#define UX_HOST_CLASS_PIMA_CT_DATA_BLOCK                        0x02
#define UX_HOST_CLASS_PIMA_CT_RESPONSE_BLOCK                    0x03
#define UX_HOST_CLASS_PIMA_CT_EVENT_BLOCK                       0x04

/* Define PIMA Extended Event Data Request payload Format.  */

#define UX_HOST_CLASS_PIMA_EEDR_EVENT_CODE                      0x00
#define UX_HOST_CLASS_PIMA_EEDR_TRANSACTION_ID                  0x02
#define UX_HOST_CLASS_PIMA_EEDR_NUMBER_PARAMETERS               0x06
#define UX_HOST_CLASS_PIMA_EEDR_SIZE_PARAMETER                  0x08

/* Define PIMA Device Status Data Format.  */

#define UX_HOST_CLASS_PIMA_DSD_LENGTH                           0x00
#define UX_HOST_CLASS_PIMA_DSD_CODE                             0x02
#define UX_HOST_CLASS_PIMA_DSD_PARAMETER                        0x04

/* Define PIMA Command Header Format.  */

#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_LENGTH                0x00
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_TYPE                  0x04
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_CODE                  0x06
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_TRANSACTION_ID        0x08
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_PARAMETER_1           0x0C
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_PARAMETER_2           0x10
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_PARAMETER_3           0x14
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_PARAMETER_4           0x18
#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_PARAMETER_5           0x1C

#define UX_HOST_CLASS_PIMA_COMMAND_HEADER_SIZE                  0x0C
#define UX_HOST_CLASS_PIMA_CONTAINER_SIZE                       512
#define UX_HOST_CLASS_PIMA_ALL_HEADER_SIZE                      0x20

/* Define PIMA Data Header Format.  */

#define UX_HOST_CLASS_PIMA_DATA_HEADER_LENGTH                   0x00
#define UX_HOST_CLASS_PIMA_DATA_HEADER_TYPE                     0x04
#define UX_HOST_CLASS_PIMA_DATA_HEADER_CODE                     0x06
#define UX_HOST_CLASS_PIMA_DATA_HEADER_TRANSACTION_ID           0x08
#define UX_HOST_CLASS_PIMA_DATA_HEADER_SIZE                     0x0C


/* Define PIMA Response Header Format.  */

#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_LENGTH               0x00
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_TYPE                 0x04
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_CODE                 0x06
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_TRANSACTION_ID       0x08
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_PARAMETER_1          0x0C
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_PARAMETER_2          0x10
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_PARAMETER_3          0x14
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_PARAMETER_4          0x18
#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_PARAMETER_5          0x1C

#define UX_HOST_CLASS_PIMA_RESPONSE_HEADER_SIZE                 0x20

/* Define PIMA Asynchronous Event Interrupt Data Format.  */

#define UX_HOST_CLASS_PIMA_AEI_DATA_LENGTH                      0x00
#define UX_HOST_CLASS_PIMA_AEI_TYPE                             0x04
#define UX_HOST_CLASS_PIMA_AEI_EVENT_CODE                       0x06
#define UX_HOST_CLASS_PIMA_AEI_TRANSACTION_ID                   0x08
#define UX_HOST_CLASS_PIMA_AEI_PARAMETER_1                      0x0C
#define UX_HOST_CLASS_PIMA_AEI_PARAMETER_2                      0x10
#define UX_HOST_CLASS_PIMA_AEI_PARAMETER_3                      0x14
#define UX_HOST_CLASS_PIMA_AEI_MAX_LENGTH                       0x18

/* Define PIMA Operation Commands.  */

#define UX_HOST_CLASS_PIMA_OC_UNDEFINED                         0x1000
#define UX_HOST_CLASS_PIMA_OC_GET_DEVICE_INFO                   0x1001
#define UX_HOST_CLASS_PIMA_OC_OPEN_SESSION                      0x1002
#define UX_HOST_CLASS_PIMA_OC_CLOSE_SESSION                     0x1003
#define UX_HOST_CLASS_PIMA_OC_GET_STORAGE_IDS                   0x1004
#define UX_HOST_CLASS_PIMA_OC_GET_STORAGE_INFO                  0x1005
#define UX_HOST_CLASS_PIMA_OC_GET_NUM_OBJECTS                   0x1006
#define UX_HOST_CLASS_PIMA_OC_GET_OBJECT_HANDLES                0x1007
#define UX_HOST_CLASS_PIMA_OC_GET_OBJECT_INFO                   0x1008
#define UX_HOST_CLASS_PIMA_OC_GET_OBJECT                        0x1009
#define UX_HOST_CLASS_PIMA_OC_GET_THUMB                         0x100A
#define UX_HOST_CLASS_PIMA_OC_DELETE_OBJECT                     0x100B
#define UX_HOST_CLASS_PIMA_OC_SEND_OBJECT_INFO                  0x100C
#define UX_HOST_CLASS_PIMA_OC_SEND_OBJECT                       0x100D
#define UX_HOST_CLASS_PIMA_OC_INITIATE_CAPTURE                  0x100E
#define UX_HOST_CLASS_PIMA_OC_FORMAT_STORE                      0x100F
#define UX_HOST_CLASS_PIMA_OC_RESET_DEVICE                      0x1010
#define UX_HOST_CLASS_PIMA_OC_SELF_TEST                         0x1011
#define UX_HOST_CLASS_PIMA_OC_SET_OBJECT_PROTECTION             0x1012
#define UX_HOST_CLASS_PIMA_OC_POWER_DOWN                        0x1013
#define UX_HOST_CLASS_PIMA_OC_GET_DEVICE_PROP_DESC              0x1014
#define UX_HOST_CLASS_PIMA_OC_GET_DEVICE_PROP_VALUE             0x1015
#define UX_HOST_CLASS_PIMA_OC_SET_DEVICE_PROP_VALUE             0x1016
#define UX_HOST_CLASS_PIMA_OC_RESET_DEVICE_PROP_VALUE           0x1017
#define UX_HOST_CLASS_PIMA_OC_TERMINATE_OPEN_CAPTURE            0x1018
#define UX_HOST_CLASS_PIMA_OC_MOVE_OBJECT                       0x1019
#define UX_HOST_CLASS_PIMA_OC_COPY_OBJECT                       0x101A
#define UX_HOST_CLASS_PIMA_OC_GET_PARTIAL_OBJECT                0x101B
#define UX_HOST_CLASS_PIMA_OC_INITIATE_OPEN_CAPTURE             0x101C
#define UX_HOST_CLASS_PIMA_OC_AMBA_SET_DATETIME                 0x7701
#define UX_HOST_CLASS_PIMA_OC_AMBA_GET_DATETIME                 0x7702
#define UX_HOST_CLASS_PIMA_OC_VENDOR_COMMAND                    0xFFFF

/* Define PIMA Response Codes.  */

#define UX_HOST_CLASS_PIMA_RC_UNDEFINED                         0x2000
#define UX_HOST_CLASS_PIMA_RC_OK                                0x2001
#define UX_HOST_CLASS_PIMA_RC_GENERAL_ERROR                     0x2002
#define UX_HOST_CLASS_PIMA_RC_SESSION_NOT_OPEN                  0x2003
#define UX_HOST_CLASS_PIMA_RC_INVALID_TRANSACTION_ID            0x2004
#define UX_HOST_CLASS_PIMA_RC_OPERATION_NOT_SUPPORTED           0x2005
#define UX_HOST_CLASS_PIMA_RC_PARAMETER_NOT_SUPPORTED           0x2006
#define UX_HOST_CLASS_PIMA_RC_INCOMPLETE_TRANSFER               0x2007
#define UX_HOST_CLASS_PIMA_RC_INVALID_STORAGE_ID                0x2008
#define UX_HOST_CLASS_PIMA_RC_INVALID_OBJECT_HANDLE             0x2009
#define UX_HOST_CLASS_PIMA_RC_DEVICE_PROP_NOT_SUPPORTED         0x200A
#define UX_HOST_CLASS_PIMA_RC_INVALID_OBJECT_FORMAT_CODE        0x200B
#define UX_HOST_CLASS_PIMA_RC_STORE_FULL                        0x200C
#define UX_HOST_CLASS_PIMA_RC_OBJECT_WRITE_PROTECTED            0x200D
#define UX_HOST_CLASS_PIMA_RC_STORE_READ_ONLY                   0x200E
#define UX_HOST_CLASS_PIMA_RC_ACCESS_DENIED                     0x200F
#define UX_HOST_CLASS_PIMA_RC_NO_THUMBNAIL_PRESENT              0x2010
#define UX_HOST_CLASS_PIMA_RC_SELF_TEST_FAILED                  0x2011
#define UX_HOST_CLASS_PIMA_RC_PARTIAL_DELETION                  0x2012
#define UX_HOST_CLASS_PIMA_RC_STORE_NOT_AVAILABLE               0x2013
#define UX_HOST_CLASS_PIMA_RC_FORMAT_UNSUPPORTED                0x2014
#define UX_HOST_CLASS_PIMA_RC_NO_VALID_OBJECT_INFO              0x2015
#define UX_HOST_CLASS_PIMA_RC_INVALID_CODE_FORMAT               0x2016
#define UX_HOST_CLASS_PIMA_RC_UNKNOWN_VENDOR_CODE               0x2017
#define UX_HOST_CLASS_PIMA_RC_CAPTURE_ALREADY_TERMINATED        0x2018
#define UX_HOST_CLASS_PIMA_RC_DEVICE_BUSY                       0x2019
#define UX_HOST_CLASS_PIMA_RC_INVALID_PARENT_OBJECT             0x201A
#define UX_HOST_CLASS_PIMA_RC_INVALID_DEVICE_PROP_FORMAT        0x201B
#define UX_HOST_CLASS_PIMA_RC_INVALID_DEVICE_PROP_VALUE         0x201C
#define UX_HOST_CLASS_PIMA_RC_INVALID_PARAMETER                 0x201D
#define UX_HOST_CLASS_PIMA_RC_SESSION_ALREADY_OPENED            0x201E
#define UX_HOST_CLASS_PIMA_RC_TRANSACTION_CANCELED              0x201F
#define UX_HOST_CLASS_PIMA_RC_DESTINATION_UNSUPPORTED           0x2020
#define UX_HOST_CLASS_PIMA_RC_OBJECT_ALREADY_OPENED             0x2021
#define UX_HOST_CLASS_PIMA_RC_OBJECT_ALREADY_CLOSED             0x2022
#define UX_HOST_CLASS_PIMA_RC_OBJECT_NOT_OPENED                 0x2023

/* Define PIMA Event Codes.  */

#define UX_HOST_CLASS_PIMA_EC_UNDEFINED                         0x4000
#define UX_HOST_CLASS_PIMA_EC_CANCEL_TRANSACTION                0x4001
#define UX_HOST_CLASS_PIMA_EC_OBJECT_ADDED                      0x4002
#define UX_HOST_CLASS_PIMA_EC_OBJECT_REMOVED                    0x4003
#define UX_HOST_CLASS_PIMA_EC_STORE_ADDED                       0x4004
#define UX_HOST_CLASS_PIMA_EC_STORE_REMOVED                     0x4005
#define UX_HOST_CLASS_PIMA_EC_DEVICE_PROP_CHANGED               0x4006
#define UX_HOST_CLASS_PIMA_EC_OBJECT_INFO_CHANGED               0x4007
#define UX_HOST_CLASS_PIMA_EC_DEVICE_INFO_CHANGED               0x4008
#define UX_HOST_CLASS_PIMA_EC_REQUEST_OBJECT_TRANSFER           0x4009
#define UX_HOST_CLASS_PIMA_EC_STORE_FULL                        0x400A
#define UX_HOST_CLASS_PIMA_EC_DEVICE_RESET                      0x400B
#define UX_HOST_CLASS_PIMA_EC_STORAGE_INFO_CHANGED              0x400C
#define UX_HOST_CLASS_PIMA_EC_CAPTURE_COMPLETE                  0x400D
#define UX_HOST_CLASS_PIMA_EC_UNREPORTED_STATUS                 0x400E

/* Define PIMA Object Format Codes.  */

#define UX_HOST_CLASS_PIMA_OFC_UNDEFINED                        0x3000
#define UX_HOST_CLASS_PIMA_OFC_ASSOCIATION                      0x3001
#define UX_HOST_CLASS_PIMA_OFC_SCRIPT                           0x3002
#define UX_HOST_CLASS_PIMA_OFC_EXECUTABLE                       0x3003
#define UX_HOST_CLASS_PIMA_OFC_TEXT                             0x3004
#define UX_HOST_CLASS_PIMA_OFC_HTML                             0x3005
#define UX_HOST_CLASS_PIMA_OFC_DPOF                             0x3006
#define UX_HOST_CLASS_PIMA_OFC_AIFF                             0x3007
#define UX_HOST_CLASS_PIMA_OFC_WAV                              0x3008
#define UX_HOST_CLASS_PIMA_OFC_MP3                              0x3009
#define UX_HOST_CLASS_PIMA_OFC_AVI                              0x300A
#define UX_HOST_CLASS_PIMA_OFC_MPEG                             0x300B
#define UX_HOST_CLASS_PIMA_OFC_ASF                              0x300C
#define UX_HOST_CLASS_PIMA_OFC_QT                               0x300D
#define UX_HOST_CLASS_PIMA_OFC_EXIF_JPEG                        0x3801
#define UX_HOST_CLASS_PIMA_OFC_TIFF_EP                          0x3802
#define UX_HOST_CLASS_PIMA_OFC_FLASHPIX                         0x3803
#define UX_HOST_CLASS_PIMA_OFC_BMP                              0x3804
#define UX_HOST_CLASS_PIMA_OFC_CIFF                             0x3805
#define UX_HOST_CLASS_PIMA_OFC_GIF                              0x3807
#define UX_HOST_CLASS_PIMA_OFC_JFIF                             0x3808
#define UX_HOST_CLASS_PIMA_OFC_PCD                              0x3809
#define UX_HOST_CLASS_PIMA_OFC_PICT                             0x380A
#define UX_HOST_CLASS_PIMA_OFC_PNG                              0x380B
#define UX_HOST_CLASS_PIMA_OFC_TIFF                             0x380D
#define UX_HOST_CLASS_PIMA_OFC_TIFF_IT                          0x380E
#define UX_HOST_CLASS_PIMA_OFC_JP2                              0x380F
#define UX_HOST_CLASS_PIMA_OFC_JPX                              0x3810

/* Define PIMA Object Protection Status Values.  */

#define UX_HOST_CLASS_PIMA_OPS_NO_PROTECTION                    0x0000
#define UX_HOST_CLASS_PIMA_OPS_READ_ONLY                        0x0001

/* Define PIMA Storage Types Codes.  */

#define UX_HOST_CLASS_PIMA_STC_UNDEFINED                        0x0000
#define UX_HOST_CLASS_PIMA_STC_FIXED_ROM                        0x0001
#define UX_HOST_CLASS_PIMA_STC_REMOVABLE_ROM                    0x0002
#define UX_HOST_CLASS_PIMA_STC_FIXED_RAM                        0x0003
#define UX_HOST_CLASS_PIMA_STC_REMOVABLE_RAM                    0x0004

/* Define PIMA File System Types Codes.  */

#define UX_HOST_CLASS_PIMA_FSTC_UNDEFINED                       0x0000
#define UX_HOST_CLASS_PIMA_FSTC_GENERIC_FLAT                    0x0001
#define UX_HOST_CLASS_PIMA_FSTC_GENERIC_HIERARCHICAL            0x0002
#define UX_HOST_CLASS_PIMA_FSTC_DCF                             0x0003

/* Define PIMA event info structure.  */

typedef struct UX_HOST_CLASS_PIMA_EVENT_STRUCT
{
    struct UX_HOST_CLASS_PIMA_SESSION_STRUCT
                    *session;
    struct UX_HOST_CLASS_PIMA_STRUCT
                    *instance;
    ULONG           code;
    ULONG           session_id;
    ULONG           transaction_id;
    ULONG           parameter_1;
    ULONG           parameter_2;
    ULONG           parameter_3;

} UX_HOST_CLASS_PIMA_EVENT, USBH_MTP_EVENT;

/* Define PIMA structure.  */

typedef struct UX_HOST_CLASS_PIMA_STRUCT
{

    struct UX_HOST_CLASS_PIMA_STRUCT
                    *ux_host_class_pima_next_instance;
    UX_HOST_CLASS   *ux_host_class_pima_class;
    UX_DEVICE       *ux_host_class_pima_device;
    UX_INTERFACE    *ux_host_class_pima_interface;
    UX_ENDPOINT     *ux_host_class_pima_bulk_out_endpoint;
    UX_ENDPOINT     *ux_host_class_pima_bulk_in_endpoint;
    UX_ENDPOINT     *ux_host_class_pima_interrupt_endpoint;
    UINT            ux_host_class_pima_state;
    ULONG           ux_host_class_pima_transaction_id;
    ULONG           ux_host_class_pima_operation_code;
    ULONG           ux_host_class_pima_event_code;
    ULONG           ux_host_class_pima_event_transaction_id;
    ULONG           ux_host_class_pima_event_session;
    ULONG           ux_host_class_pima_event_parameter_1;
    ULONG           ux_host_class_pima_event_parameter_2;
    ULONG           ux_host_class_pima_event_parameter_3;
    UCHAR           *ux_host_class_pima_event_buffer;
    UCHAR           *ux_host_class_pima_event_buffer_current_offset;
    ULONG           ux_host_class_pima_event_buffer_current_length;
    ULONG           ux_host_class_pima_event_buffer_expected_length;
    struct UX_HOST_CLASS_PIMA_SESSION_STRUCT
                    *ux_host_class_pima_session;
    UCHAR           *ux_host_class_pima_container;
    TX_SEMAPHORE    ux_host_class_pima_semaphore;
    VOID            *ux_host_class_pima_application;
    ULONG           ux_host_class_pima_zlp_flag;

} UX_HOST_CLASS_PIMA;

/* Define PIMA Session structure.  */

typedef struct UX_HOST_CLASS_PIMA_SESSION_STRUCT
{

    ULONG           magic;
    ULONG           id;
    ULONG           state;
    struct UX_HOST_CLASS_PIMA_STRUCT
                    *pima_instance;
    ULONG           nb_storage_ids;
    ULONG           nb_objects;
    VOID            (*event_callback)(struct UX_HOST_CLASS_PIMA_EVENT_STRUCT *pima_event);

} UX_HOST_CLASS_PIMA_SESSION, USBH_MTP_SESSION;


/* Define PIMA command structure.  */

typedef struct UX_HOST_CLASS_PIMA_COMMAND_STRUCT
{

    ULONG           nb_parameters;
    ULONG           operation_code;
    ULONG           parameter_1;
    ULONG           parameter_2;
    ULONG           parameter_3;
    ULONG           parameter_4;
    ULONG           parameter_5;
    ULONG           response_code;

} UX_HOST_CLASS_PIMA_COMMAND, USBH_MTP_COMMAND;

/* Define PIMA object info structure.  */

typedef struct UX_HOST_CLASS_PIMA_OBJECT_STRUCT
{

    ULONG           storage_id;
    ULONG           object_format;
    ULONG           protection_satus;
    ULONG           compressed_size;
    ULONG           thumb_format;
    ULONG           thumb_compressed_size;
    ULONG           thumb_pix_width;
    ULONG           thumb_pix_height;
    ULONG           image_pix_width;
    ULONG           image_pix_height;
    ULONG           image_bit_depth;
    ULONG           parent_object;
    ULONG           association_type;
    ULONG           association_desc;
    ULONG           sequence_number;
    UCHAR           filename[UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH];
    UCHAR           capture_date[UX_HOST_CLASS_PIMA_DATE_TIME_STRING_MAX_LENGTH];
    UCHAR           modification_date[UX_HOST_CLASS_PIMA_DATE_TIME_STRING_MAX_LENGTH];
    UCHAR           keywords[UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH];
    ULONG           state;
    ULONG           offset;
    ULONG           transfer_status;
    ULONG           handle_id;
    ULONG           length;
    UCHAR           *buffer;

} UX_HOST_CLASS_PIMA_OBJECT, USBH_MTP_OBJECT;

/* Define PIMA vendor data info structure.  */

typedef struct UX_HOST_CLASS_PIMA_VENDOR_PAYLOAD_STRUCT
{
    ULONG           size;
    ULONG           offset;
} UX_HOST_CLASS_PIMA_VENDOR_PAYLOAD, USBH_MTP_VENDOR_PAYLOAD;

/* Define PIMA Object decompaction structure.  */

#define UX_HOST_CLASS_PIMA_OBJECT_MAX_LENGTH                                512
#define UX_HOST_CLASS_PIMA_OBJECT_VARIABLE_OFFSET                           52
#define UX_HOST_CLASS_PIMA_OBJECT_ENTRIES                                   15

/* Define PIMA device info structure.  */

typedef struct UX_HOST_CLASS_PIMA_DEVICE_STRUCT
{

    ULONG            standard_version;
    ULONG            vendor_extension_id;
    ULONG            vendor_extension_version;
    UCHAR            vendor_extension_desc[UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH];
    ULONG            functional_mode;
    UCHAR            operations_supported[UX_HOST_CLASS_PIMA_ARRAY_MAX_LENGTH];
    UCHAR            events_supported[UX_HOST_CLASS_PIMA_ARRAY_MAX_LENGTH];
    UCHAR            properties_supported[UX_HOST_CLASS_PIMA_ARRAY_MAX_LENGTH];
    UCHAR            capture_formats[UX_HOST_CLASS_PIMA_ARRAY_MAX_LENGTH];
    UCHAR            image_formats[UX_HOST_CLASS_PIMA_ARRAY_MAX_LENGTH];
    UCHAR            manufacturer[UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH];
    UCHAR            model[UX_HOST_CLASS_PIMA_DATE_TIME_STRING_MAX_LENGTH];
    UCHAR            version[UX_HOST_CLASS_PIMA_DATE_TIME_STRING_MAX_LENGTH];
    UCHAR            serial_number[UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH];

} UX_HOST_CLASS_PIMA_DEVICE, USBH_MTP_DEVICE;

/* Define PIMA Device decompaction structure.  */

#define UX_HOST_CLASS_PIMA_DEVICE_MAX_LENGTH                                512
#define UX_HOST_CLASS_PIMA_DEVICE_STANDARD_VERSION                          0
#define UX_HOST_CLASS_PIMA_DEVICE_VENDOR_EXTENSION_ID                       2
#define UX_HOST_CLASS_PIMA_DEVICE_VENDOR_EXTENSION_VERSION                  6
#define UX_HOST_CLASS_PIMA_DEVICE_VENDOR_EXTENSION_DESC                     8

/* Define PIMA storage info structure.  */

typedef struct UX_HOST_CLASS_PIMA_STORAGE_STRUCT
{

    ULONG            type;
    ULONG            file_system_type;
    ULONG            access_capability;
    ULONG            max_capacity_low;
    ULONG            max_capacity_high;
    ULONG            free_space_bytes_low;
    ULONG            free_space_bytes_high;
    ULONG            free_space_images;
    UCHAR            description[UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH];
    UCHAR            volume_label[UX_HOST_CLASS_PIMA_UNICODE_MAX_LENGTH];

} UX_HOST_CLASS_PIMA_STORAGE, USBH_MTP_STORAGE;

/* Define PIMA storage decompaction structure.  */

#define UX_HOST_CLASS_PIMA_STORAGE_MAX_LENGTH                             512
#define UX_HOST_CLASS_PIMA_STORAGE_VARIABLE_OFFSET                        26
#define UX_HOST_CLASS_PIMA_STORAGE_ENTRIES                                8

/* Define Pima Class function prototypes.  */

UINT  _ux_host_class_pima_activate(UX_HOST_CLASS_COMMAND *command);
UINT  _ux_host_class_pima_configure(UX_HOST_CLASS_PIMA *cdc_acm);
UINT  _ux_host_class_pima_deactivate(UX_HOST_CLASS_COMMAND *command);
UINT  _ux_host_class_pima_endpoints_get(UX_HOST_CLASS_PIMA *cdc_acm);
UINT  _ux_host_class_pima_entry(UX_HOST_CLASS_COMMAND *command);
VOID  _ux_host_class_pima_notification(UX_TRANSFER *transfer_request);
UINT  _ux_host_class_pima_command(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_COMMAND *command,
                                    ULONG direction, UCHAR *data_buffer, ULONG data_length,
                                    ULONG max_payload_length);
UINT  _ux_host_class_pima_num_objects_get(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG storage_id,
                                        ULONG object_format_code, ULONG association);
UINT  _ux_host_class_pima_object_copy(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG object_handle,
                                        ULONG storage_id, ULONG parent_object_handle);
UINT  _ux_host_class_pima_object_delete(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG object_handle, ULONG format_code);
UINT  _ux_host_class_pima_object_get(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG object_handle, UX_HOST_CLASS_PIMA_OBJECT *object,
                                        UCHAR *object_buffer, ULONG object_buffer_length, ULONG *object_actual_length);
UINT  _ux_host_class_pima_object_handles_get(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session,
                                    ULONG *object_handles_array, ULONG object_handles_length, ULONG storage_id, ULONG object_format_code, ULONG object_handle_association);
UINT  _ux_host_class_pima_object_info_get(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG object_handle, UX_HOST_CLASS_PIMA_OBJECT *object);
UINT  _ux_host_class_pima_object_info_send(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG storage_id, ULONG parent_object_id,
                                        UX_HOST_CLASS_PIMA_OBJECT *object);
UINT  _ux_host_class_pima_object_move(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG object_handle, ULONG storage_id, ULONG parent_object_handle);
UINT  _ux_host_class_pima_object_send(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, UX_HOST_CLASS_PIMA_OBJECT *object,
                                        UCHAR *object_buffer, ULONG object_buffer_length);
UINT  _ux_host_class_pima_read(UX_HOST_CLASS_PIMA *pima, UCHAR *data_pointer, ULONG data_length, ULONG max_payload_length);
UINT  _ux_host_class_pima_session_close(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session);
UINT  _ux_host_class_pima_session_open(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session);
UINT  _ux_host_class_pima_storage_ids_get(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG *storage_ids_array, ULONG storage_id_length);
UINT  _ux_host_class_pima_storage_info_get(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG storage_id, UX_HOST_CLASS_PIMA_STORAGE *storage);
UINT  _ux_host_class_pima_thumb_get(UX_HOST_CLASS_PIMA *pima, UX_HOST_CLASS_PIMA_SESSION *pima_session, ULONG object_handle, ULONG format_code,
		                            UX_HOST_CLASS_PIMA_OBJECT *object, UCHAR *thumb_buffer, ULONG thumb_buffer_length, ULONG *thumb_actual_length);
UINT  _ux_host_class_pima_write(UX_HOST_CLASS_PIMA *pima, UCHAR *data_pointer, ULONG data_length, ULONG operation_code, ULONG max_payload_length);
UINT  _ux_host_class_pima_request_cancel(UX_HOST_CLASS_PIMA *pima);
UINT  _ux_host_class_pima_object_transfer_abort(UX_HOST_CLASS_PIMA *pima,
                                        UX_HOST_CLASS_PIMA_SESSION *pima_session,
                                        ULONG object_handle, UX_HOST_CLASS_PIMA_OBJECT *object);
UINT  _ux_host_class_pima_object_close(UX_HOST_CLASS_PIMA *pima,
                                        UX_HOST_CLASS_PIMA_SESSION *pima_session,
                                        ULONG object_handle, UX_HOST_CLASS_PIMA_OBJECT *object);
UINT  _ux_host_class_pima_object_open(UX_HOST_CLASS_PIMA *pima,
                                        UX_HOST_CLASS_PIMA_SESSION *pima_session,
                                        ULONG object_handle, UX_HOST_CLASS_PIMA_OBJECT *object);
UINT  _ux_host_class_pima_device_info_get(UX_HOST_CLASS_PIMA *pima,
                                        UX_HOST_CLASS_PIMA_DEVICE *pima_device);
UINT  _ux_host_class_pima_device_reset(UX_HOST_CLASS_PIMA *pima);

UINT  _ux_host_class_pima_response_get(UX_HOST_CLASS_PIMA *pima,
		                               UX_HOST_CLASS_PIMA_COMMAND *command);

UINT  _ux_host_class_pima_vendor_command(UX_HOST_CLASS_PIMA *pima,
                                         UX_HOST_CLASS_PIMA_SESSION *pima_session,
                                         ULONG *params);

UINT  _ux_host_class_pima_vendor_command_send(UX_HOST_CLASS_PIMA *pima,
                                              UX_HOST_CLASS_PIMA_SESSION *pima_session,
                                              UX_HOST_CLASS_PIMA_COMMAND *command,
                                              UX_HOST_CLASS_PIMA_VENDOR_PAYLOAD * vendor_payload,
                                              UINT8 *payload_buffer,
                                              ULONG payload_buffer_length);

UINT  _ux_host_class_pima_vendor_command_get(UX_HOST_CLASS_PIMA *pima,
                                             UX_HOST_CLASS_PIMA_SESSION *pima_session,
                                             UX_HOST_CLASS_PIMA_COMMAND *command,
                                             UX_HOST_CLASS_PIMA_VENDOR_PAYLOAD * vendor_payload,
                                             UINT8 *payload_buffer,
                                             ULONG  payload_buffer_length,
                                             ULONG *payload_actual_length);

VOID _ux_host_class_pima_get_response_code(UX_HOST_CLASS_PIMA_COMMAND* response);
VOID _ux_host_class_pima_set_response_code(UX_HOST_CLASS_PIMA_COMMAND* response);

#endif