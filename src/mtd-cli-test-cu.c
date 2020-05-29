/* SPDX-License-Identifier: GPL-2.0 */

/*
 * mtd-cli-tesst-cu.c - Make Tax Digital - Create Test User
 *
 * Copyright (C) 2020		Andrew Clayton <andrew@digital-domain.net>
 */

#include <stddef.h>

#include <libmtdac/mtd-test-cu.h>

#include "mtd-cli.h"

#define MTD_CLI_CMD	MTD_CLI " test-cu "

static const char * const API_NAME = "Create Test User";
static const char * const CMDS =
"create-individual create-organisation create-agent list-services";

static const struct endpoint endpoints[] = {
	{
		.name = "create-individual",
		.api_func = {
			.func_1 = mtd_test_cu_create_individual
		},
		.func = FUNC_1,
		.nr_req_args = 1,
		.use = MTD_CLI_CMD "create-individual <file>"
	},
	{
		.name = "create-organisation",
		.api_func = {
			.func_1 = mtd_test_cu_create_organisation
		},
		.func = FUNC_1,
		.nr_req_args = 1,
		.use = MTD_CLI_CMD "create-organisation <file>"
	},
	{
		.name = "create-agent",
		.api_func = {
			.func_1 = mtd_test_cu_create_agent
		},
		.func = FUNC_1,
		.nr_req_args = 1,
		.use = MTD_CLI_CMD "create-agent <file?"
	},
	{
		.name = "list-services",
		.api_func = {
			.func_0 = mtd_test_cu_list_services
		},
		.func = FUNC_0,
		.nr_req_args = 0,
		.use = MTD_CLI_CMD "list-services"
	},
	{ NULL, { NULL }, 0, 0, NULL }
};

const struct _endpoint test_cu_endpoint = {
	.endpoints = endpoints,
	.api_name = API_NAME,
	.cmds = CMDS
};
