/*
 * Copyright (c) 2022, sakumisu
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef USBD_HID_H
#define USBD_HID_H

#include "usb_hid.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Alloc hid interface driver */
struct usbd_interface *usbd_hid_alloc_intf(const uint8_t *desc, uint32_t desc_len);

/* Register desc api */
void usbd_hid_descriptor_register(uint8_t intf_num, const uint8_t *desc);
void usbd_hid_report_descriptor_register(uint8_t intf_num, const uint8_t *desc, uint32_t desc_len);

/* Setup request command callback api */
uint8_t usbh_hid_get_report(uint8_t intf, uint8_t report_id, uint8_t report_type);
uint8_t usbh_hid_get_idle(uint8_t intf, uint8_t report_id);
uint8_t usbh_hid_get_protocol(uint8_t intf);
void usbh_hid_set_report(uint8_t intf, uint8_t report_id, uint8_t report_type, uint8_t *report, uint8_t report_len);
void usbh_hid_set_idle(uint8_t intf, uint8_t report_id, uint8_t duration);
void usbh_hid_set_protocol(uint8_t intf, uint8_t protocol);

#ifdef __cplusplus
}
#endif

#endif /* USBD_HID_H */