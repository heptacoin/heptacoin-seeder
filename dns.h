// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2017 The Heptacoin Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file LICENSE or http://www.opensource.org/licenses/mit-license.php.

#ifndef _DNS_H_
#define _DNS_H_ 1

#include <stdint.h>

typedef struct {
    int v;
    union {
       unsigned char v4[4];
       unsigned char v6[16];
    } data;
} addr_t;

typedef struct {
  int port;
  int datattl;
  int nsttl;
  const char *host;
  const char *ns;
  const char *mbox;
  int (*cb)(void *opt, char *requested_hostname, addr_t *addr, int max, int ipv4, int ipv6);
  // stats
  uint64_t nRequests;
} dns_opt_t;

extern int dnsserver(dns_opt_t *opt);

#endif
