/*-------------------------------------------------------------------------
 *
 * identity.h
 *	  Segment identity.
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 *-------------------------------------------------------------------------
 */

#ifndef IDENTITY_H
#define IDENTITY_H

#include "utils/relcache.h"
#include "nodes/primnodes.h"
#include "nodes/pg_list.h"


struct SegmentIdentity;
struct ProcessIdentity;

typedef struct SegmentFunctionList
{
	bool	login_as_default;

	bool	module_motion;
	bool	module_log_sync;
} SegmentFunctionList;

typedef struct ProcessFunctionList
{
} ProcessFunctionList;

#define SEGMENT_IDENTITY_NAME_LENGTH	256

typedef struct ProcessIdentity
{
	bool		init;

	/* Member that assign by Dispatcher. */
	int			slice_id;			/* slice id. */
	int			id_in_slice;		/* index in the slice. allocate during dispatch */
	int			gang_member_num;	/* num of qes in the slice. */
	int			command_count;		/* gp_command_count */
	bool		is_writer;			/* Metadata dispatch needs query executor access heap interface, so combocid need it. */
	TransactionId	xid;

	/* Member that generated by above data. */
	char		name[SEGMENT_IDENTITY_NAME_LENGTH];	/* Query Executor Name */

	ProcessFunctionList	function;
} ProcessIdentity;

extern int slaveHostNumber;

extern void SetSegmentIdentity(const char *name);
extern bool IsOnMaster(void);
extern const char *SerializeProcessIdentity(struct ProcessIdentity *id, int *msg_len);
extern bool SetupProcessIdentity(const char *str);

extern bool AmIMaster(void);
extern bool AmIStandby(void);
extern bool AmISegment(void);
extern bool AmIGtm(void);
extern bool AmICatalogService(void);

/* Assert used for everyone */
#define		AssertOnMaster()		Assert(AmIMaster());
#define		AssertOnSegment()		Assert(AmISegment());

#endif   /* IDENTITY_H */