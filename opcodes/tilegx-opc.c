/* TILE-Gx opcode information.

   Copyright 2011 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
    MA 02110-1301, USA.  */

/* This define is BFD_RELOC_##x for real bfd, or -1 for everyone else.  */
#define BFD_RELOC(x) BFD_RELOC_##x

#include "bfd.h"

/* Special registers.  */
#define TREG_LR   55
#define TREG_SN   56
#define TREG_ZERO 63

#if defined(__KERNEL__) || defined(_LIBC)
/* FIXME: Rename this. */
#include <asm/opcode-tile_64.h>
#define DISASM_ONLY
#else
#include "opcode/tilegx.h"
#endif

#ifdef __KERNEL__
#include <linux/stddef.h>
#else
#include <stddef.h>
#endif

const struct tilegx_opcode tilegx_opcodes[336] =
{
 { "bpt", TILEGX_OPC_BPT, 0x2, 0, TREG_ZERO, 0,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffffffff80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a44ae00000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "info", TILEGX_OPC_INFO, 0xf, 1, TREG_ZERO, 1,
    { { 0 }, { 1 }, { 2 }, { 3 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00fffULL,
      0xfff807ff80000000ULL,
      0x0000000078000fffULL,
      0x3c0007ff80000000ULL,
      0ULL
    },
    {
      0x0000000040300fffULL,
      0x181807ff80000000ULL,
      0x0000000010000fffULL,
      0x0c0007ff80000000ULL,
      -1ULL
    }
#endif
  },
  { "infol", TILEGX_OPC_INFOL, 0x3, 1, TREG_ZERO, 1,
    { { 4 }, { 5 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc000000070000fffULL,
      0xf80007ff80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000070000fffULL,
      0x380007ff80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld4s_tls", TILEGX_OPC_LD4S_TLS, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1858000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld_tls", TILEGX_OPC_LD_TLS, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18a0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "move", TILEGX_OPC_MOVE, 0xf, 2, TREG_ZERO, 1,
    { { 8, 9 }, { 6, 7 }, { 10, 11 }, { 12, 13 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0xfffff80000000000ULL,
      0x00000000780ff000ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      0x000000005107f000ULL,
      0x283bf80000000000ULL,
      0x00000000500bf000ULL,
      0x2c05f80000000000ULL,
      -1ULL
    }
#endif
  },
  { "movei", TILEGX_OPC_MOVEI, 0xf, 2, TREG_ZERO, 1,
    { { 8, 0 }, { 6, 1 }, { 10, 2 }, { 12, 3 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00fc0ULL,
      0xfff807e000000000ULL,
      0x0000000078000fc0ULL,
      0x3c0007e000000000ULL,
      0ULL
    },
    {
      0x0000000040100fc0ULL,
      0x180807e000000000ULL,
      0x0000000000000fc0ULL,
      0x040007e000000000ULL,
      -1ULL
    }
#endif
  },
  { "moveli", TILEGX_OPC_MOVELI, 0x3, 2, TREG_ZERO, 1,
    { { 8, 4 }, { 6, 5 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc000000070000fc0ULL,
      0xf80007e000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000010000fc0ULL,
      0x000007e000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "prefetch", TILEGX_OPC_PREFETCH, 0x12, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff81f80000000ULL,
      0ULL,
      0ULL,
      0xc3f8000004000000ULL
    },
    {
      -1ULL,
      0x286a801f80000000ULL,
      -1ULL,
      -1ULL,
      0x41f8000004000000ULL
    }
#endif
  },
  { "prefetch_add_l1", TILEGX_OPC_PREFETCH_ADD_L1, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8001f80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1840001f80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "prefetch_add_l1_fault", TILEGX_OPC_PREFETCH_ADD_L1_FAULT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8001f80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1838001f80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "prefetch_add_l2", TILEGX_OPC_PREFETCH_ADD_L2, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8001f80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1850001f80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "prefetch_add_l2_fault", TILEGX_OPC_PREFETCH_ADD_L2_FAULT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8001f80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1848001f80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "prefetch_add_l3", TILEGX_OPC_PREFETCH_ADD_L3, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8001f80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1860001f80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "prefetch_add_l3_fault", TILEGX_OPC_PREFETCH_ADD_L3_FAULT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8001f80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1858001f80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "prefetch_l1", TILEGX_OPC_PREFETCH_L1, 0x12, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff81f80000000ULL,
      0ULL,
      0ULL,
      0xc3f8000004000000ULL
    },
    {
      -1ULL,
      0x286a801f80000000ULL,
      -1ULL,
      -1ULL,
      0x41f8000004000000ULL
    }
#endif
  },
  { "prefetch_l1_fault", TILEGX_OPC_PREFETCH_L1_FAULT, 0x12, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff81f80000000ULL,
      0ULL,
      0ULL,
      0xc3f8000004000000ULL
    },
    {
      -1ULL,
      0x286a781f80000000ULL,
      -1ULL,
      -1ULL,
      0x41f8000000000000ULL
    }
#endif
  },
  { "prefetch_l2", TILEGX_OPC_PREFETCH_L2, 0x12, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff81f80000000ULL,
      0ULL,
      0ULL,
      0xc3f8000004000000ULL
    },
    {
      -1ULL,
      0x286a901f80000000ULL,
      -1ULL,
      -1ULL,
      0x43f8000004000000ULL
    }
#endif
  },
  { "prefetch_l2_fault", TILEGX_OPC_PREFETCH_L2_FAULT, 0x12, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff81f80000000ULL,
      0ULL,
      0ULL,
      0xc3f8000004000000ULL
    },
    {
      -1ULL,
      0x286a881f80000000ULL,
      -1ULL,
      -1ULL,
      0x43f8000000000000ULL
    }
#endif
  },
  { "prefetch_l3", TILEGX_OPC_PREFETCH_L3, 0x12, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff81f80000000ULL,
      0ULL,
      0ULL,
      0xc3f8000004000000ULL
    },
    {
      -1ULL,
      0x286aa01f80000000ULL,
      -1ULL,
      -1ULL,
      0x83f8000000000000ULL
    }
#endif
  },
  { "prefetch_l3_fault", TILEGX_OPC_PREFETCH_L3_FAULT, 0x12, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff81f80000000ULL,
      0ULL,
      0ULL,
      0xc3f8000004000000ULL
    },
    {
      -1ULL,
      0x286a981f80000000ULL,
      -1ULL,
      -1ULL,
      0x81f8000004000000ULL
    }
#endif
  },
  { "raise", TILEGX_OPC_RAISE, 0x2, 0, TREG_ZERO, 1,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffffffff80000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a44ae80000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "add", TILEGX_OPC_ADD, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x00000000500c0000ULL,
      0x2806000000000000ULL,
      0x0000000028040000ULL,
      0x1802000000000000ULL,
      -1ULL
    }
#endif
  },
  { "addi", TILEGX_OPC_ADDI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 10, 11, 2 }, { 12, 13, 3 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0x0000000078000000ULL,
      0x3c00000000000000ULL,
      0ULL
    },
    {
      0x0000000040100000ULL,
      0x1808000000000000ULL,
      0ULL,
      0x0400000000000000ULL,
      -1ULL
    }
#endif
  },
  { "addli", TILEGX_OPC_ADDLI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 4 }, { 6, 7, 5 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc000000070000000ULL,
      0xf800000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000010000000ULL,
      0ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "addx", TILEGX_OPC_ADDX, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050080000ULL,
      0x2804000000000000ULL,
      0x0000000028000000ULL,
      0x1800000000000000ULL,
      -1ULL
    }
#endif
  },
  { "addxi", TILEGX_OPC_ADDXI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 10, 11, 2 }, { 12, 13, 3 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0x0000000078000000ULL,
      0x3c00000000000000ULL,
      0ULL
    },
    {
      0x0000000040200000ULL,
      0x1810000000000000ULL,
      0x0000000008000000ULL,
      0x0800000000000000ULL,
      -1ULL
    }
#endif
  },
  { "addxli", TILEGX_OPC_ADDXLI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 4 }, { 6, 7, 5 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc000000070000000ULL,
      0xf800000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000020000000ULL,
      0x0800000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "addxsc", TILEGX_OPC_ADDXSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050040000ULL,
      0x2802000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "and", TILEGX_OPC_AND, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050100000ULL,
      0x2808000000000000ULL,
      0x0000000050000000ULL,
      0x2c00000000000000ULL,
      -1ULL
    }
#endif
  },
  { "andi", TILEGX_OPC_ANDI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 10, 11, 2 }, { 12, 13, 3 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0x0000000078000000ULL,
      0x3c00000000000000ULL,
      0ULL
    },
    {
      0x0000000040300000ULL,
      0x1818000000000000ULL,
      0x0000000010000000ULL,
      0x0c00000000000000ULL,
      -1ULL
    }
#endif
  },
  { "beqz", TILEGX_OPC_BEQZ, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1440000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "beqzt", TILEGX_OPC_BEQZT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1400000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bfexts", TILEGX_OPC_BFEXTS, 0x1, 4, TREG_ZERO, 1,
    { { 8, 9, 21, 22 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007f000000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000034000000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bfextu", TILEGX_OPC_BFEXTU, 0x1, 4, TREG_ZERO, 1,
    { { 8, 9, 21, 22 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007f000000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000035000000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bfins", TILEGX_OPC_BFINS, 0x1, 4, TREG_ZERO, 1,
    { { 23, 9, 21, 22 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007f000000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000036000000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bgez", TILEGX_OPC_BGEZ, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x14c0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bgezt", TILEGX_OPC_BGEZT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1480000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bgtz", TILEGX_OPC_BGTZ, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1540000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bgtzt", TILEGX_OPC_BGTZT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1500000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "blbc", TILEGX_OPC_BLBC, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x15c0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "blbct", TILEGX_OPC_BLBCT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1580000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "blbs", TILEGX_OPC_BLBS, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1640000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "blbst", TILEGX_OPC_BLBST, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1600000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "blez", TILEGX_OPC_BLEZ, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x16c0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "blezt", TILEGX_OPC_BLEZT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1680000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bltz", TILEGX_OPC_BLTZ, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1740000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bltzt", TILEGX_OPC_BLTZT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1700000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bnez", TILEGX_OPC_BNEZ, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x17c0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "bnezt", TILEGX_OPC_BNEZT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 20 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xffc0000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1780000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "clz", TILEGX_OPC_CLZ, 0x5, 2, TREG_ZERO, 1,
    { { 8, 9 }, { 0, }, { 10, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051481000ULL,
      -1ULL,
      0x00000000300c1000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmoveqz", TILEGX_OPC_CMOVEQZ, 0x5, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 24, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050140000ULL,
      -1ULL,
      0x0000000048000000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmovnez", TILEGX_OPC_CMOVNEZ, 0x5, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 24, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050180000ULL,
      -1ULL,
      0x0000000048040000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmpeq", TILEGX_OPC_CMPEQ, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x00000000501c0000ULL,
      0x280a000000000000ULL,
      0x0000000040000000ULL,
      0x2404000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmpeqi", TILEGX_OPC_CMPEQI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 10, 11, 2 }, { 12, 13, 3 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0x0000000078000000ULL,
      0x3c00000000000000ULL,
      0ULL
    },
    {
      0x0000000040400000ULL,
      0x1820000000000000ULL,
      0x0000000018000000ULL,
      0x1000000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmpexch", TILEGX_OPC_CMPEXCH, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x280e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmpexch4", TILEGX_OPC_CMPEXCH4, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x280c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmples", TILEGX_OPC_CMPLES, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050200000ULL,
      0x2810000000000000ULL,
      0x0000000038000000ULL,
      0x2000000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmpleu", TILEGX_OPC_CMPLEU, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050240000ULL,
      0x2812000000000000ULL,
      0x0000000038040000ULL,
      0x2002000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmplts", TILEGX_OPC_CMPLTS, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050280000ULL,
      0x2814000000000000ULL,
      0x0000000038080000ULL,
      0x2004000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmpltsi", TILEGX_OPC_CMPLTSI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 10, 11, 2 }, { 12, 13, 3 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0x0000000078000000ULL,
      0x3c00000000000000ULL,
      0ULL
    },
    {
      0x0000000040500000ULL,
      0x1828000000000000ULL,
      0x0000000020000000ULL,
      0x1400000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmpltu", TILEGX_OPC_CMPLTU, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x00000000502c0000ULL,
      0x2816000000000000ULL,
      0x00000000380c0000ULL,
      0x2006000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmpltui", TILEGX_OPC_CMPLTUI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040600000ULL,
      0x1830000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmpne", TILEGX_OPC_CMPNE, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050300000ULL,
      0x2818000000000000ULL,
      0x0000000040040000ULL,
      0x2406000000000000ULL,
      -1ULL
    }
#endif
  },
  { "cmul", TILEGX_OPC_CMUL, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000504c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmula", TILEGX_OPC_CMULA, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050380000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmulaf", TILEGX_OPC_CMULAF, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050340000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmulf", TILEGX_OPC_CMULF, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050400000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmulfr", TILEGX_OPC_CMULFR, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000503c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmulh", TILEGX_OPC_CMULH, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050480000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "cmulhr", TILEGX_OPC_CMULHR, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050440000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "crc32_32", TILEGX_OPC_CRC32_32, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050500000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "crc32_8", TILEGX_OPC_CRC32_8, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050540000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ctz", TILEGX_OPC_CTZ, 0x5, 2, TREG_ZERO, 1,
    { { 8, 9 }, { 0, }, { 10, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051482000ULL,
      -1ULL,
      0x00000000300c2000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "dblalign", TILEGX_OPC_DBLALIGN, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050640000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "dblalign2", TILEGX_OPC_DBLALIGN2, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050580000ULL,
      0x281a000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "dblalign4", TILEGX_OPC_DBLALIGN4, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000505c0000ULL,
      0x281c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "dblalign6", TILEGX_OPC_DBLALIGN6, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050600000ULL,
      0x281e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "drain", TILEGX_OPC_DRAIN, 0x2, 0, TREG_ZERO, 0,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a080000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "dtlbpr", TILEGX_OPC_DTLBPR, 0x2, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a100000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "exch", TILEGX_OPC_EXCH, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2822000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "exch4", TILEGX_OPC_EXCH4, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2820000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_add_flags", TILEGX_OPC_FDOUBLE_ADD_FLAGS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000506c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_addsub", TILEGX_OPC_FDOUBLE_ADDSUB, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050680000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_mul_flags", TILEGX_OPC_FDOUBLE_MUL_FLAGS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050700000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_pack1", TILEGX_OPC_FDOUBLE_PACK1, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050740000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_pack2", TILEGX_OPC_FDOUBLE_PACK2, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050780000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_sub_flags", TILEGX_OPC_FDOUBLE_SUB_FLAGS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000507c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_unpack_max", TILEGX_OPC_FDOUBLE_UNPACK_MAX, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050800000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fdouble_unpack_min", TILEGX_OPC_FDOUBLE_UNPACK_MIN, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050840000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchadd", TILEGX_OPC_FETCHADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x282a000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchadd4", TILEGX_OPC_FETCHADD4, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2824000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchaddgez", TILEGX_OPC_FETCHADDGEZ, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2828000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchaddgez4", TILEGX_OPC_FETCHADDGEZ4, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2826000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchand", TILEGX_OPC_FETCHAND, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x282e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchand4", TILEGX_OPC_FETCHAND4, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x282c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchor", TILEGX_OPC_FETCHOR, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2832000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fetchor4", TILEGX_OPC_FETCHOR4, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2830000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "finv", TILEGX_OPC_FINV, 0x2, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a180000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "flush", TILEGX_OPC_FLUSH, 0x2, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a280000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "flushwb", TILEGX_OPC_FLUSHWB, 0x2, 0, TREG_ZERO, 1,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a200000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fnop", TILEGX_OPC_FNOP, 0xf, 0, TREG_ZERO, 1,
    { {  }, {  }, {  }, {  }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0xfffff80000000000ULL,
      0x00000000780ff000ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      0x0000000051483000ULL,
      0x286a300000000000ULL,
      0x00000000300c3000ULL,
      0x1c06400000000000ULL,
      -1ULL
    }
#endif
  },
  { "fsingle_add1", TILEGX_OPC_FSINGLE_ADD1, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050880000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fsingle_addsub2", TILEGX_OPC_FSINGLE_ADDSUB2, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000508c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fsingle_mul1", TILEGX_OPC_FSINGLE_MUL1, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050900000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fsingle_mul2", TILEGX_OPC_FSINGLE_MUL2, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050940000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fsingle_pack1", TILEGX_OPC_FSINGLE_PACK1, 0x5, 2, TREG_ZERO, 1,
    { { 8, 9 }, { 0, }, { 10, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051484000ULL,
      -1ULL,
      0x00000000300c4000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fsingle_pack2", TILEGX_OPC_FSINGLE_PACK2, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050980000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "fsingle_sub1", TILEGX_OPC_FSINGLE_SUB1, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000509c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "icoh", TILEGX_OPC_ICOH, 0x2, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a380000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ill", TILEGX_OPC_ILL, 0xa, 0, TREG_ZERO, 1,
    { { 0, }, {  }, { 0, }, {  }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a400000000000ULL,
      -1ULL,
      0x1c06480000000000ULL,
      -1ULL
    }
#endif
  },
  { "inv", TILEGX_OPC_INV, 0x2, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a480000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "iret", TILEGX_OPC_IRET, 0x2, 0, TREG_ZERO, 1,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a500000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "j", TILEGX_OPC_J, 0x2, 1, TREG_ZERO, 1,
    { { 0, }, { 25 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfc00000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2400000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "jal", TILEGX_OPC_JAL, 0x2, 1, TREG_LR, 1,
    { { 0, }, { 25 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfc00000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2000000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "jalr", TILEGX_OPC_JALR, 0xa, 1, TREG_LR, 1,
    { { 0, }, { 7 }, { 0, }, { 13 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a600000000000ULL,
      -1ULL,
      0x1c06580000000000ULL,
      -1ULL
    }
#endif
  },
  { "jalrp", TILEGX_OPC_JALRP, 0xa, 1, TREG_LR, 1,
    { { 0, }, { 7 }, { 0, }, { 13 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a580000000000ULL,
      -1ULL,
      0x1c06500000000000ULL,
      -1ULL
    }
#endif
  },
  { "jr", TILEGX_OPC_JR, 0xa, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 13 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a700000000000ULL,
      -1ULL,
      0x1c06680000000000ULL,
      -1ULL
    }
#endif
  },
  { "jrp", TILEGX_OPC_JRP, 0xa, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 13 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      -1ULL,
      0x286a680000000000ULL,
      -1ULL,
      0x1c06600000000000ULL,
      -1ULL
    }
#endif
  },
  { "ld", TILEGX_OPC_LD, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 26, 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x286ae80000000000ULL,
      -1ULL,
      -1ULL,
      0x8200000004000000ULL
    }
#endif
  },
  { "ld1s", TILEGX_OPC_LD1S, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 26, 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x286a780000000000ULL,
      -1ULL,
      -1ULL,
      0x4000000000000000ULL
    }
#endif
  },
  { "ld1s_add", TILEGX_OPC_LD1S_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1838000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld1u", TILEGX_OPC_LD1U, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 26, 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x286a800000000000ULL,
      -1ULL,
      -1ULL,
      0x4000000004000000ULL
    }
#endif
  },
  { "ld1u_add", TILEGX_OPC_LD1U_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1840000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld2s", TILEGX_OPC_LD2S, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 26, 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x286a880000000000ULL,
      -1ULL,
      -1ULL,
      0x4200000000000000ULL
    }
#endif
  },
  { "ld2s_add", TILEGX_OPC_LD2S_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1848000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld2u", TILEGX_OPC_LD2U, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 26, 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x286a900000000000ULL,
      -1ULL,
      -1ULL,
      0x4200000004000000ULL
    }
#endif
  },
  { "ld2u_add", TILEGX_OPC_LD2U_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1850000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld4s", TILEGX_OPC_LD4S, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 26, 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x286a980000000000ULL,
      -1ULL,
      -1ULL,
      0x8000000004000000ULL
    }
#endif
  },
  { "ld4s_add", TILEGX_OPC_LD4S_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1858000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld4u", TILEGX_OPC_LD4U, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 26, 14 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x286aa00000000000ULL,
      -1ULL,
      -1ULL,
      0x8200000000000000ULL
    }
#endif
  },
  { "ld4u_add", TILEGX_OPC_LD4U_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1860000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ld_add", TILEGX_OPC_LD_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18a0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldna", TILEGX_OPC_LDNA, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286aa80000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldna_add", TILEGX_OPC_LDNA_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18a8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt", TILEGX_OPC_LDNT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286ae00000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt1s", TILEGX_OPC_LDNT1S, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286ab00000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt1s_add", TILEGX_OPC_LDNT1S_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1868000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt1u", TILEGX_OPC_LDNT1U, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286ab80000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt1u_add", TILEGX_OPC_LDNT1U_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1870000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt2s", TILEGX_OPC_LDNT2S, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286ac00000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt2s_add", TILEGX_OPC_LDNT2S_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1878000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt2u", TILEGX_OPC_LDNT2U, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286ac80000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt2u_add", TILEGX_OPC_LDNT2U_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1880000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt4s", TILEGX_OPC_LDNT4S, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286ad00000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt4s_add", TILEGX_OPC_LDNT4S_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1888000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt4u", TILEGX_OPC_LDNT4U, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286ad80000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt4u_add", TILEGX_OPC_LDNT4U_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1890000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "ldnt_add", TILEGX_OPC_LDNT_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 6, 15, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1898000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "lnk", TILEGX_OPC_LNK, 0xa, 1, TREG_ZERO, 1,
    { { 0, }, { 6 }, { 0, }, { 12 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      -1ULL,
      0x286af00000000000ULL,
      -1ULL,
      0x1c06700000000000ULL,
      -1ULL
    }
#endif
  },
  { "mf", TILEGX_OPC_MF, 0x2, 0, TREG_ZERO, 1,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286af80000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mfspr", TILEGX_OPC_MFSPR, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 6, 27 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18b0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mm", TILEGX_OPC_MM, 0x1, 4, TREG_ZERO, 1,
    { { 23, 9, 21, 22 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007f000000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000037000000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mnz", TILEGX_OPC_MNZ, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050a00000ULL,
      0x2834000000000000ULL,
      0x0000000048080000ULL,
      0x2804000000000000ULL,
      -1ULL
    }
#endif
  },
  { "mtspr", TILEGX_OPC_MTSPR, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 28, 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18b8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_hs_hs", TILEGX_OPC_MUL_HS_HS, 0x5, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 10, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050d40000ULL,
      -1ULL,
      0x0000000068000000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_hs_hu", TILEGX_OPC_MUL_HS_HU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050d80000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_hs_ls", TILEGX_OPC_MUL_HS_LS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050dc0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_hs_lu", TILEGX_OPC_MUL_HS_LU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050e00000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_hu_hu", TILEGX_OPC_MUL_HU_HU, 0x5, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 10, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050e40000ULL,
      -1ULL,
      0x0000000068040000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_hu_ls", TILEGX_OPC_MUL_HU_LS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050e80000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_hu_lu", TILEGX_OPC_MUL_HU_LU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050ec0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_ls_ls", TILEGX_OPC_MUL_LS_LS, 0x5, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 10, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050f00000ULL,
      -1ULL,
      0x0000000068080000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_ls_lu", TILEGX_OPC_MUL_LS_LU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050f40000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mul_lu_lu", TILEGX_OPC_MUL_LU_LU, 0x5, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 10, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050f80000ULL,
      -1ULL,
      0x00000000680c0000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_hs_hs", TILEGX_OPC_MULA_HS_HS, 0x5, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 24, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050a80000ULL,
      -1ULL,
      0x0000000070000000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_hs_hu", TILEGX_OPC_MULA_HS_HU, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050ac0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_hs_ls", TILEGX_OPC_MULA_HS_LS, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050b00000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_hs_lu", TILEGX_OPC_MULA_HS_LU, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050b40000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_hu_hu", TILEGX_OPC_MULA_HU_HU, 0x5, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 24, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050b80000ULL,
      -1ULL,
      0x0000000070040000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_hu_ls", TILEGX_OPC_MULA_HU_LS, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050bc0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_hu_lu", TILEGX_OPC_MULA_HU_LU, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050c00000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_ls_ls", TILEGX_OPC_MULA_LS_LS, 0x5, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 24, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050c40000ULL,
      -1ULL,
      0x0000000070080000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_ls_lu", TILEGX_OPC_MULA_LS_LU, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050c80000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mula_lu_lu", TILEGX_OPC_MULA_LU_LU, 0x5, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 24, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050cc0000ULL,
      -1ULL,
      0x00000000700c0000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mulax", TILEGX_OPC_MULAX, 0x5, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 24, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050a40000ULL,
      -1ULL,
      0x0000000040080000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mulx", TILEGX_OPC_MULX, 0x5, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 10, 11, 18 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0x00000000780c0000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000050d00000ULL,
      -1ULL,
      0x00000000400c0000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "mz", TILEGX_OPC_MZ, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000050fc0000ULL,
      0x2836000000000000ULL,
      0x00000000480c0000ULL,
      0x2806000000000000ULL,
      -1ULL
    }
#endif
  },
  { "nap", TILEGX_OPC_NAP, 0x2, 0, TREG_ZERO, 0,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286b000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "nop", TILEGX_OPC_NOP, 0xf, 0, TREG_ZERO, 1,
    { {  }, {  }, {  }, {  }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0xfffff80000000000ULL,
      0x00000000780ff000ULL,
      0x3c07f80000000000ULL,
      0ULL
    },
    {
      0x0000000051485000ULL,
      0x286b080000000000ULL,
      0x00000000300c5000ULL,
      0x1c06780000000000ULL,
      -1ULL
    }
#endif
  },
  { "nor", TILEGX_OPC_NOR, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051000000ULL,
      0x2838000000000000ULL,
      0x0000000050040000ULL,
      0x2c02000000000000ULL,
      -1ULL
    }
#endif
  },
  { "or", TILEGX_OPC_OR, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051040000ULL,
      0x283a000000000000ULL,
      0x0000000050080000ULL,
      0x2c04000000000000ULL,
      -1ULL
    }
#endif
  },
  { "ori", TILEGX_OPC_ORI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040700000ULL,
      0x18c0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "pcnt", TILEGX_OPC_PCNT, 0x5, 2, TREG_ZERO, 1,
    { { 8, 9 }, { 0, }, { 10, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051486000ULL,
      -1ULL,
      0x00000000300c6000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "revbits", TILEGX_OPC_REVBITS, 0x5, 2, TREG_ZERO, 1,
    { { 8, 9 }, { 0, }, { 10, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051487000ULL,
      -1ULL,
      0x00000000300c7000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "revbytes", TILEGX_OPC_REVBYTES, 0x5, 2, TREG_ZERO, 1,
    { { 8, 9 }, { 0, }, { 10, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051488000ULL,
      -1ULL,
      0x00000000300c8000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "rotl", TILEGX_OPC_ROTL, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051080000ULL,
      0x283c000000000000ULL,
      0x0000000058000000ULL,
      0x3000000000000000ULL,
      -1ULL
    }
#endif
  },
  { "rotli", TILEGX_OPC_ROTLI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 10, 11, 31 }, { 12, 13, 32 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000060040000ULL,
      0x3002000000000000ULL,
      0x0000000078000000ULL,
      0x3800000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shl", TILEGX_OPC_SHL, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051280000ULL,
      0x284c000000000000ULL,
      0x0000000058040000ULL,
      0x3002000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shl16insli", TILEGX_OPC_SHL16INSLI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 4 }, { 6, 7, 5 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc000000070000000ULL,
      0xf800000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000070000000ULL,
      0x3800000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "shl1add", TILEGX_OPC_SHL1ADD, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051100000ULL,
      0x2840000000000000ULL,
      0x0000000030000000ULL,
      0x1c00000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shl1addx", TILEGX_OPC_SHL1ADDX, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x00000000510c0000ULL,
      0x283e000000000000ULL,
      0x0000000060040000ULL,
      0x3402000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shl2add", TILEGX_OPC_SHL2ADD, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051180000ULL,
      0x2844000000000000ULL,
      0x0000000030040000ULL,
      0x1c02000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shl2addx", TILEGX_OPC_SHL2ADDX, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051140000ULL,
      0x2842000000000000ULL,
      0x0000000060080000ULL,
      0x3404000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shl3add", TILEGX_OPC_SHL3ADD, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051200000ULL,
      0x2848000000000000ULL,
      0x0000000030080000ULL,
      0x1c04000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shl3addx", TILEGX_OPC_SHL3ADDX, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x00000000511c0000ULL,
      0x2846000000000000ULL,
      0x00000000600c0000ULL,
      0x3406000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shli", TILEGX_OPC_SHLI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 10, 11, 31 }, { 12, 13, 32 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000060080000ULL,
      0x3004000000000000ULL,
      0x0000000078040000ULL,
      0x3802000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shlx", TILEGX_OPC_SHLX, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051240000ULL,
      0x284a000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "shlxi", TILEGX_OPC_SHLXI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000600c0000ULL,
      0x3006000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "shrs", TILEGX_OPC_SHRS, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x00000000512c0000ULL,
      0x284e000000000000ULL,
      0x0000000058080000ULL,
      0x3004000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shrsi", TILEGX_OPC_SHRSI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 10, 11, 31 }, { 12, 13, 32 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000060100000ULL,
      0x3008000000000000ULL,
      0x0000000078080000ULL,
      0x3804000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shru", TILEGX_OPC_SHRU, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051340000ULL,
      0x2852000000000000ULL,
      0x00000000580c0000ULL,
      0x3006000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shrui", TILEGX_OPC_SHRUI, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 10, 11, 31 }, { 12, 13, 32 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000060140000ULL,
      0x300a000000000000ULL,
      0x00000000780c0000ULL,
      0x3806000000000000ULL,
      -1ULL
    }
#endif
  },
  { "shrux", TILEGX_OPC_SHRUX, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051300000ULL,
      0x2850000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "shruxi", TILEGX_OPC_SHRUXI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000060180000ULL,
      0x300c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "shufflebytes", TILEGX_OPC_SHUFFLEBYTES, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051380000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "st", TILEGX_OPC_ST, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 14, 33 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x2862000000000000ULL,
      -1ULL,
      -1ULL,
      0xc200000004000000ULL
    }
#endif
  },
  { "st1", TILEGX_OPC_ST1, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 14, 33 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x2854000000000000ULL,
      -1ULL,
      -1ULL,
      0xc000000000000000ULL
    }
#endif
  },
  { "st1_add", TILEGX_OPC_ST1_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18c8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "st2", TILEGX_OPC_ST2, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 14, 33 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x2856000000000000ULL,
      -1ULL,
      -1ULL,
      0xc000000004000000ULL
    }
#endif
  },
  { "st2_add", TILEGX_OPC_ST2_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18d0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "st4", TILEGX_OPC_ST4, 0x12, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 14, 33 } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0xc200000004000000ULL
    },
    {
      -1ULL,
      0x2858000000000000ULL,
      -1ULL,
      -1ULL,
      0xc200000000000000ULL
    }
#endif
  },
  { "st4_add", TILEGX_OPC_ST4_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18d8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "st_add", TILEGX_OPC_ST_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x1900000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt", TILEGX_OPC_STNT, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x2860000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt1", TILEGX_OPC_STNT1, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x285a000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt1_add", TILEGX_OPC_STNT1_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18e0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt2", TILEGX_OPC_STNT2, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x285c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt2_add", TILEGX_OPC_STNT2_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18e8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt4", TILEGX_OPC_STNT4, 0x2, 2, TREG_ZERO, 1,
    { { 0, }, { 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x285e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt4_add", TILEGX_OPC_STNT4_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18f0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "stnt_add", TILEGX_OPC_STNT_ADD, 0x2, 3, TREG_ZERO, 1,
    { { 0, }, { 15, 17, 34 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x18f8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "sub", TILEGX_OPC_SUB, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051440000ULL,
      0x2868000000000000ULL,
      0x00000000280c0000ULL,
      0x1806000000000000ULL,
      -1ULL
    }
#endif
  },
  { "subx", TILEGX_OPC_SUBX, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000051400000ULL,
      0x2866000000000000ULL,
      0x0000000028080000ULL,
      0x1804000000000000ULL,
      -1ULL
    }
#endif
  },
  { "subxsc", TILEGX_OPC_SUBXSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000513c0000ULL,
      0x2864000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "swint0", TILEGX_OPC_SWINT0, 0x2, 0, TREG_ZERO, 0,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286b100000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "swint1", TILEGX_OPC_SWINT1, 0x2, 0, TREG_ZERO, 0,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286b180000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "swint2", TILEGX_OPC_SWINT2, 0x2, 0, TREG_ZERO, 0,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286b200000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "swint3", TILEGX_OPC_SWINT3, 0x2, 0, TREG_ZERO, 0,
    { { 0, }, {  }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286b280000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "tblidxb0", TILEGX_OPC_TBLIDXB0, 0x5, 2, TREG_ZERO, 1,
    { { 23, 9 }, { 0, }, { 24, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051489000ULL,
      -1ULL,
      0x00000000300c9000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "tblidxb1", TILEGX_OPC_TBLIDXB1, 0x5, 2, TREG_ZERO, 1,
    { { 23, 9 }, { 0, }, { 24, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x000000005148a000ULL,
      -1ULL,
      0x00000000300ca000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "tblidxb2", TILEGX_OPC_TBLIDXB2, 0x5, 2, TREG_ZERO, 1,
    { { 23, 9 }, { 0, }, { 24, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x000000005148b000ULL,
      -1ULL,
      0x00000000300cb000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "tblidxb3", TILEGX_OPC_TBLIDXB3, 0x5, 2, TREG_ZERO, 1,
    { { 23, 9 }, { 0, }, { 24, 11 }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffff000ULL,
      0ULL,
      0x00000000780ff000ULL,
      0ULL,
      0ULL
    },
    {
      0x000000005148c000ULL,
      -1ULL,
      0x00000000300cc000ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1add", TILEGX_OPC_V1ADD, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051500000ULL,
      0x286e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1addi", TILEGX_OPC_V1ADDI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040800000ULL,
      0x1908000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1adduc", TILEGX_OPC_V1ADDUC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000514c0000ULL,
      0x286c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1adiffu", TILEGX_OPC_V1ADIFFU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051540000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1avgu", TILEGX_OPC_V1AVGU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051580000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmpeq", TILEGX_OPC_V1CMPEQ, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000515c0000ULL,
      0x2870000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmpeqi", TILEGX_OPC_V1CMPEQI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040900000ULL,
      0x1910000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmples", TILEGX_OPC_V1CMPLES, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051600000ULL,
      0x2872000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmpleu", TILEGX_OPC_V1CMPLEU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051640000ULL,
      0x2874000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmplts", TILEGX_OPC_V1CMPLTS, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051680000ULL,
      0x2876000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmpltsi", TILEGX_OPC_V1CMPLTSI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040a00000ULL,
      0x1918000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmpltu", TILEGX_OPC_V1CMPLTU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000516c0000ULL,
      0x2878000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmpltui", TILEGX_OPC_V1CMPLTUI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040b00000ULL,
      0x1920000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1cmpne", TILEGX_OPC_V1CMPNE, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051700000ULL,
      0x287a000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1ddotpu", TILEGX_OPC_V1DDOTPU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052880000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1ddotpua", TILEGX_OPC_V1DDOTPUA, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052840000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1ddotpus", TILEGX_OPC_V1DDOTPUS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051780000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1ddotpusa", TILEGX_OPC_V1DDOTPUSA, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051740000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1dotp", TILEGX_OPC_V1DOTP, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051880000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1dotpa", TILEGX_OPC_V1DOTPA, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000517c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1dotpu", TILEGX_OPC_V1DOTPU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052900000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1dotpua", TILEGX_OPC_V1DOTPUA, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000528c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1dotpus", TILEGX_OPC_V1DOTPUS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051840000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1dotpusa", TILEGX_OPC_V1DOTPUSA, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051800000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1int_h", TILEGX_OPC_V1INT_H, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000518c0000ULL,
      0x287c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1int_l", TILEGX_OPC_V1INT_L, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051900000ULL,
      0x287e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1maxu", TILEGX_OPC_V1MAXU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051940000ULL,
      0x2880000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1maxui", TILEGX_OPC_V1MAXUI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040c00000ULL,
      0x1928000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1minu", TILEGX_OPC_V1MINU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051980000ULL,
      0x2882000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1minui", TILEGX_OPC_V1MINUI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040d00000ULL,
      0x1930000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1mnz", TILEGX_OPC_V1MNZ, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000519c0000ULL,
      0x2884000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1multu", TILEGX_OPC_V1MULTU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051a00000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1mulu", TILEGX_OPC_V1MULU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051a80000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1mulus", TILEGX_OPC_V1MULUS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051a40000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1mz", TILEGX_OPC_V1MZ, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051ac0000ULL,
      0x2886000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1sadau", TILEGX_OPC_V1SADAU, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051b00000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1sadu", TILEGX_OPC_V1SADU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051b40000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1shl", TILEGX_OPC_V1SHL, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051b80000ULL,
      0x2888000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1shli", TILEGX_OPC_V1SHLI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000601c0000ULL,
      0x300e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1shrs", TILEGX_OPC_V1SHRS, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051bc0000ULL,
      0x288a000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1shrsi", TILEGX_OPC_V1SHRSI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000060200000ULL,
      0x3010000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1shru", TILEGX_OPC_V1SHRU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051c00000ULL,
      0x288c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1shrui", TILEGX_OPC_V1SHRUI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000060240000ULL,
      0x3012000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1sub", TILEGX_OPC_V1SUB, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051c80000ULL,
      0x2890000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v1subuc", TILEGX_OPC_V1SUBUC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051c40000ULL,
      0x288e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2add", TILEGX_OPC_V2ADD, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051d00000ULL,
      0x2894000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2addi", TILEGX_OPC_V2ADDI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040e00000ULL,
      0x1938000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2addsc", TILEGX_OPC_V2ADDSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051cc0000ULL,
      0x2892000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2adiffs", TILEGX_OPC_V2ADIFFS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051d40000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2avgs", TILEGX_OPC_V2AVGS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051d80000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmpeq", TILEGX_OPC_V2CMPEQ, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051dc0000ULL,
      0x2896000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmpeqi", TILEGX_OPC_V2CMPEQI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000040f00000ULL,
      0x1940000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmples", TILEGX_OPC_V2CMPLES, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051e00000ULL,
      0x2898000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmpleu", TILEGX_OPC_V2CMPLEU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051e40000ULL,
      0x289a000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmplts", TILEGX_OPC_V2CMPLTS, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051e80000ULL,
      0x289c000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmpltsi", TILEGX_OPC_V2CMPLTSI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000041000000ULL,
      0x1948000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmpltu", TILEGX_OPC_V2CMPLTU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051ec0000ULL,
      0x289e000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmpltui", TILEGX_OPC_V2CMPLTUI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000041100000ULL,
      0x1950000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2cmpne", TILEGX_OPC_V2CMPNE, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051f00000ULL,
      0x28a0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2dotp", TILEGX_OPC_V2DOTP, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051f80000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2dotpa", TILEGX_OPC_V2DOTPA, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051f40000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2int_h", TILEGX_OPC_V2INT_H, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000051fc0000ULL,
      0x28a2000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2int_l", TILEGX_OPC_V2INT_L, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052000000ULL,
      0x28a4000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2maxs", TILEGX_OPC_V2MAXS, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052040000ULL,
      0x28a6000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2maxsi", TILEGX_OPC_V2MAXSI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000041200000ULL,
      0x1958000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2mins", TILEGX_OPC_V2MINS, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052080000ULL,
      0x28a8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2minsi", TILEGX_OPC_V2MINSI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000041300000ULL,
      0x1960000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2mnz", TILEGX_OPC_V2MNZ, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000520c0000ULL,
      0x28aa000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2mulfsc", TILEGX_OPC_V2MULFSC, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052100000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2muls", TILEGX_OPC_V2MULS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052140000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2mults", TILEGX_OPC_V2MULTS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052180000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2mz", TILEGX_OPC_V2MZ, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000521c0000ULL,
      0x28ac000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2packh", TILEGX_OPC_V2PACKH, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052200000ULL,
      0x28ae000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2packl", TILEGX_OPC_V2PACKL, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052240000ULL,
      0x28b0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2packuc", TILEGX_OPC_V2PACKUC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052280000ULL,
      0x28b2000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2sadas", TILEGX_OPC_V2SADAS, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000522c0000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2sadau", TILEGX_OPC_V2SADAU, 0x1, 3, TREG_ZERO, 1,
    { { 23, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052300000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2sads", TILEGX_OPC_V2SADS, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052340000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2sadu", TILEGX_OPC_V2SADU, 0x1, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 0, }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052380000ULL,
      -1ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2shl", TILEGX_OPC_V2SHL, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052400000ULL,
      0x28b6000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2shli", TILEGX_OPC_V2SHLI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000060280000ULL,
      0x3014000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2shlsc", TILEGX_OPC_V2SHLSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000523c0000ULL,
      0x28b4000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2shrs", TILEGX_OPC_V2SHRS, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052440000ULL,
      0x28b8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2shrsi", TILEGX_OPC_V2SHRSI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000602c0000ULL,
      0x3016000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2shru", TILEGX_OPC_V2SHRU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052480000ULL,
      0x28ba000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2shrui", TILEGX_OPC_V2SHRUI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 29 }, { 6, 7, 30 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000060300000ULL,
      0x3018000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2sub", TILEGX_OPC_V2SUB, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052500000ULL,
      0x28be000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v2subsc", TILEGX_OPC_V2SUBSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000524c0000ULL,
      0x28bc000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4add", TILEGX_OPC_V4ADD, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052580000ULL,
      0x28c2000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4addsc", TILEGX_OPC_V4ADDSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052540000ULL,
      0x28c0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4int_h", TILEGX_OPC_V4INT_H, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000525c0000ULL,
      0x28c4000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4int_l", TILEGX_OPC_V4INT_L, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052600000ULL,
      0x28c6000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4packsc", TILEGX_OPC_V4PACKSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052640000ULL,
      0x28c8000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4shl", TILEGX_OPC_V4SHL, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000526c0000ULL,
      0x28cc000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4shlsc", TILEGX_OPC_V4SHLSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052680000ULL,
      0x28ca000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4shrs", TILEGX_OPC_V4SHRS, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052700000ULL,
      0x28ce000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4shru", TILEGX_OPC_V4SHRU, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052740000ULL,
      0x28d0000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4sub", TILEGX_OPC_V4SUB, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x00000000527c0000ULL,
      0x28d4000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "v4subsc", TILEGX_OPC_V4SUBSC, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000052780000ULL,
      0x28d2000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "wh64", TILEGX_OPC_WH64, 0x2, 1, TREG_ZERO, 1,
    { { 0, }, { 7 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0ULL,
      0xfffff80000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      -1ULL,
      0x286b300000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { "xor", TILEGX_OPC_XOR, 0xf, 3, TREG_ZERO, 1,
    { { 8, 9, 16 }, { 6, 7, 17 }, { 10, 11, 18 }, { 12, 13, 19 }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ffc0000ULL,
      0xfffe000000000000ULL,
      0x00000000780c0000ULL,
      0x3c06000000000000ULL,
      0ULL
    },
    {
      0x0000000052800000ULL,
      0x28d6000000000000ULL,
      0x00000000500c0000ULL,
      0x2c06000000000000ULL,
      -1ULL
    }
#endif
  },
  { "xori", TILEGX_OPC_XORI, 0x3, 3, TREG_ZERO, 1,
    { { 8, 9, 0 }, { 6, 7, 1 }, { 0, }, { 0, }, { 0, } },
#ifndef DISASM_ONLY
    {
      0xc00000007ff00000ULL,
      0xfff8000000000000ULL,
      0ULL,
      0ULL,
      0ULL
    },
    {
      0x0000000041400000ULL,
      0x1968000000000000ULL,
      -1ULL,
      -1ULL,
      -1ULL
    }
#endif
  },
  { NULL, TILEGX_OPC_NONE, 0, 0, TREG_ZERO, 0, { { 0, } },
#ifndef DISASM_ONLY
    { 0, }, { 0, }
#endif
  }
};
#define BITFIELD(start, size) ((start) | (((1 << (size)) - 1) << 6))
#define CHILD(array_index) (TILEGX_OPC_NONE + (array_index))

static const unsigned short decode_X0_fsm[936] =
{
  BITFIELD(22, 9) /* index 0 */,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_BFEXTS,
  TILEGX_OPC_BFEXTS, TILEGX_OPC_BFEXTS, TILEGX_OPC_BFEXTS, TILEGX_OPC_BFEXTU,
  TILEGX_OPC_BFEXTU, TILEGX_OPC_BFEXTU, TILEGX_OPC_BFEXTU, TILEGX_OPC_BFINS,
  TILEGX_OPC_BFINS, TILEGX_OPC_BFINS, TILEGX_OPC_BFINS, TILEGX_OPC_MM,
  TILEGX_OPC_MM, TILEGX_OPC_MM, TILEGX_OPC_MM, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, CHILD(528), CHILD(578),
  CHILD(583), CHILD(588), CHILD(593), CHILD(598), TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, CHILD(603), CHILD(620), CHILD(637), CHILD(654), CHILD(671),
  CHILD(703), CHILD(797), CHILD(814), CHILD(831), CHILD(848), CHILD(865),
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, CHILD(889), TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  CHILD(906), CHILD(906), CHILD(906), CHILD(906), CHILD(906),
  BITFIELD(6, 2) /* index 513 */,
  TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, CHILD(518),
  BITFIELD(8, 2) /* index 518 */,
  TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, CHILD(523),
  BITFIELD(10, 2) /* index 523 */,
  TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_MOVELI,
  BITFIELD(20, 2) /* index 528 */,
  TILEGX_OPC_NONE, CHILD(533), TILEGX_OPC_ADDXI, CHILD(548),
  BITFIELD(6, 2) /* index 533 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(538),
  BITFIELD(8, 2) /* index 538 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(543),
  BITFIELD(10, 2) /* index 543 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_MOVEI,
  BITFIELD(0, 2) /* index 548 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(553),
  BITFIELD(2, 2) /* index 553 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(558),
  BITFIELD(4, 2) /* index 558 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(563),
  BITFIELD(6, 2) /* index 563 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(568),
  BITFIELD(8, 2) /* index 568 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(573),
  BITFIELD(10, 2) /* index 573 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_INFO,
  BITFIELD(20, 2) /* index 578 */,
  TILEGX_OPC_CMPEQI, TILEGX_OPC_CMPLTSI, TILEGX_OPC_CMPLTUI, TILEGX_OPC_ORI,
  BITFIELD(20, 2) /* index 583 */,
  TILEGX_OPC_V1ADDI, TILEGX_OPC_V1CMPEQI, TILEGX_OPC_V1CMPLTSI,
  TILEGX_OPC_V1CMPLTUI,
  BITFIELD(20, 2) /* index 588 */,
  TILEGX_OPC_V1MAXUI, TILEGX_OPC_V1MINUI, TILEGX_OPC_V2ADDI,
  TILEGX_OPC_V2CMPEQI,
  BITFIELD(20, 2) /* index 593 */,
  TILEGX_OPC_V2CMPLTSI, TILEGX_OPC_V2CMPLTUI, TILEGX_OPC_V2MAXSI,
  TILEGX_OPC_V2MINSI,
  BITFIELD(20, 2) /* index 598 */,
  TILEGX_OPC_XORI, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(18, 4) /* index 603 */,
  TILEGX_OPC_NONE, TILEGX_OPC_ADDXSC, TILEGX_OPC_ADDX, TILEGX_OPC_ADD,
  TILEGX_OPC_AND, TILEGX_OPC_CMOVEQZ, TILEGX_OPC_CMOVNEZ, TILEGX_OPC_CMPEQ,
  TILEGX_OPC_CMPLES, TILEGX_OPC_CMPLEU, TILEGX_OPC_CMPLTS, TILEGX_OPC_CMPLTU,
  TILEGX_OPC_CMPNE, TILEGX_OPC_CMULAF, TILEGX_OPC_CMULA, TILEGX_OPC_CMULFR,
  BITFIELD(18, 4) /* index 620 */,
  TILEGX_OPC_CMULF, TILEGX_OPC_CMULHR, TILEGX_OPC_CMULH, TILEGX_OPC_CMUL,
  TILEGX_OPC_CRC32_32, TILEGX_OPC_CRC32_8, TILEGX_OPC_DBLALIGN2,
  TILEGX_OPC_DBLALIGN4, TILEGX_OPC_DBLALIGN6, TILEGX_OPC_DBLALIGN,
  TILEGX_OPC_FDOUBLE_ADDSUB, TILEGX_OPC_FDOUBLE_ADD_FLAGS,
  TILEGX_OPC_FDOUBLE_MUL_FLAGS, TILEGX_OPC_FDOUBLE_PACK1,
  TILEGX_OPC_FDOUBLE_PACK2, TILEGX_OPC_FDOUBLE_SUB_FLAGS,
  BITFIELD(18, 4) /* index 637 */,
  TILEGX_OPC_FDOUBLE_UNPACK_MAX, TILEGX_OPC_FDOUBLE_UNPACK_MIN,
  TILEGX_OPC_FSINGLE_ADD1, TILEGX_OPC_FSINGLE_ADDSUB2,
  TILEGX_OPC_FSINGLE_MUL1, TILEGX_OPC_FSINGLE_MUL2, TILEGX_OPC_FSINGLE_PACK2,
  TILEGX_OPC_FSINGLE_SUB1, TILEGX_OPC_MNZ, TILEGX_OPC_MULAX,
  TILEGX_OPC_MULA_HS_HS, TILEGX_OPC_MULA_HS_HU, TILEGX_OPC_MULA_HS_LS,
  TILEGX_OPC_MULA_HS_LU, TILEGX_OPC_MULA_HU_HU, TILEGX_OPC_MULA_HU_LS,
  BITFIELD(18, 4) /* index 654 */,
  TILEGX_OPC_MULA_HU_LU, TILEGX_OPC_MULA_LS_LS, TILEGX_OPC_MULA_LS_LU,
  TILEGX_OPC_MULA_LU_LU, TILEGX_OPC_MULX, TILEGX_OPC_MUL_HS_HS,
  TILEGX_OPC_MUL_HS_HU, TILEGX_OPC_MUL_HS_LS, TILEGX_OPC_MUL_HS_LU,
  TILEGX_OPC_MUL_HU_HU, TILEGX_OPC_MUL_HU_LS, TILEGX_OPC_MUL_HU_LU,
  TILEGX_OPC_MUL_LS_LS, TILEGX_OPC_MUL_LS_LU, TILEGX_OPC_MUL_LU_LU,
  TILEGX_OPC_MZ,
  BITFIELD(18, 4) /* index 671 */,
  TILEGX_OPC_NOR, CHILD(688), TILEGX_OPC_ROTL, TILEGX_OPC_SHL1ADDX,
  TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL2ADDX, TILEGX_OPC_SHL2ADD,
  TILEGX_OPC_SHL3ADDX, TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHLX, TILEGX_OPC_SHL,
  TILEGX_OPC_SHRS, TILEGX_OPC_SHRUX, TILEGX_OPC_SHRU, TILEGX_OPC_SHUFFLEBYTES,
  TILEGX_OPC_SUBXSC,
  BITFIELD(12, 2) /* index 688 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(693),
  BITFIELD(14, 2) /* index 693 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(698),
  BITFIELD(16, 2) /* index 698 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_MOVE,
  BITFIELD(18, 4) /* index 703 */,
  TILEGX_OPC_SUBX, TILEGX_OPC_SUB, CHILD(720), TILEGX_OPC_V1ADDUC,
  TILEGX_OPC_V1ADD, TILEGX_OPC_V1ADIFFU, TILEGX_OPC_V1AVGU,
  TILEGX_OPC_V1CMPEQ, TILEGX_OPC_V1CMPLES, TILEGX_OPC_V1CMPLEU,
  TILEGX_OPC_V1CMPLTS, TILEGX_OPC_V1CMPLTU, TILEGX_OPC_V1CMPNE,
  TILEGX_OPC_V1DDOTPUSA, TILEGX_OPC_V1DDOTPUS, TILEGX_OPC_V1DOTPA,
  BITFIELD(12, 4) /* index 720 */,
  TILEGX_OPC_NONE, CHILD(737), CHILD(742), CHILD(747), CHILD(752), CHILD(757),
  CHILD(762), CHILD(767), CHILD(772), CHILD(777), CHILD(782), CHILD(787),
  CHILD(792), TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 737 */,
  TILEGX_OPC_CLZ, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 742 */,
  TILEGX_OPC_CTZ, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 747 */,
  TILEGX_OPC_FNOP, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 752 */,
  TILEGX_OPC_FSINGLE_PACK1, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 757 */,
  TILEGX_OPC_NOP, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 762 */,
  TILEGX_OPC_PCNT, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 767 */,
  TILEGX_OPC_REVBITS, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 772 */,
  TILEGX_OPC_REVBYTES, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 777 */,
  TILEGX_OPC_TBLIDXB0, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 782 */,
  TILEGX_OPC_TBLIDXB1, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 787 */,
  TILEGX_OPC_TBLIDXB2, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(16, 2) /* index 792 */,
  TILEGX_OPC_TBLIDXB3, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(18, 4) /* index 797 */,
  TILEGX_OPC_V1DOTPUSA, TILEGX_OPC_V1DOTPUS, TILEGX_OPC_V1DOTP,
  TILEGX_OPC_V1INT_H, TILEGX_OPC_V1INT_L, TILEGX_OPC_V1MAXU,
  TILEGX_OPC_V1MINU, TILEGX_OPC_V1MNZ, TILEGX_OPC_V1MULTU, TILEGX_OPC_V1MULUS,
  TILEGX_OPC_V1MULU, TILEGX_OPC_V1MZ, TILEGX_OPC_V1SADAU, TILEGX_OPC_V1SADU,
  TILEGX_OPC_V1SHL, TILEGX_OPC_V1SHRS,
  BITFIELD(18, 4) /* index 814 */,
  TILEGX_OPC_V1SHRU, TILEGX_OPC_V1SUBUC, TILEGX_OPC_V1SUB, TILEGX_OPC_V2ADDSC,
  TILEGX_OPC_V2ADD, TILEGX_OPC_V2ADIFFS, TILEGX_OPC_V2AVGS,
  TILEGX_OPC_V2CMPEQ, TILEGX_OPC_V2CMPLES, TILEGX_OPC_V2CMPLEU,
  TILEGX_OPC_V2CMPLTS, TILEGX_OPC_V2CMPLTU, TILEGX_OPC_V2CMPNE,
  TILEGX_OPC_V2DOTPA, TILEGX_OPC_V2DOTP, TILEGX_OPC_V2INT_H,
  BITFIELD(18, 4) /* index 831 */,
  TILEGX_OPC_V2INT_L, TILEGX_OPC_V2MAXS, TILEGX_OPC_V2MINS, TILEGX_OPC_V2MNZ,
  TILEGX_OPC_V2MULFSC, TILEGX_OPC_V2MULS, TILEGX_OPC_V2MULTS, TILEGX_OPC_V2MZ,
  TILEGX_OPC_V2PACKH, TILEGX_OPC_V2PACKL, TILEGX_OPC_V2PACKUC,
  TILEGX_OPC_V2SADAS, TILEGX_OPC_V2SADAU, TILEGX_OPC_V2SADS,
  TILEGX_OPC_V2SADU, TILEGX_OPC_V2SHLSC,
  BITFIELD(18, 4) /* index 848 */,
  TILEGX_OPC_V2SHL, TILEGX_OPC_V2SHRS, TILEGX_OPC_V2SHRU, TILEGX_OPC_V2SUBSC,
  TILEGX_OPC_V2SUB, TILEGX_OPC_V4ADDSC, TILEGX_OPC_V4ADD, TILEGX_OPC_V4INT_H,
  TILEGX_OPC_V4INT_L, TILEGX_OPC_V4PACKSC, TILEGX_OPC_V4SHLSC,
  TILEGX_OPC_V4SHL, TILEGX_OPC_V4SHRS, TILEGX_OPC_V4SHRU, TILEGX_OPC_V4SUBSC,
  TILEGX_OPC_V4SUB,
  BITFIELD(18, 3) /* index 865 */,
  CHILD(874), CHILD(877), CHILD(880), CHILD(883), CHILD(886), TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(21, 1) /* index 874 */,
  TILEGX_OPC_XOR, TILEGX_OPC_NONE,
  BITFIELD(21, 1) /* index 877 */,
  TILEGX_OPC_V1DDOTPUA, TILEGX_OPC_NONE,
  BITFIELD(21, 1) /* index 880 */,
  TILEGX_OPC_V1DDOTPU, TILEGX_OPC_NONE,
  BITFIELD(21, 1) /* index 883 */,
  TILEGX_OPC_V1DOTPUA, TILEGX_OPC_NONE,
  BITFIELD(21, 1) /* index 886 */,
  TILEGX_OPC_V1DOTPU, TILEGX_OPC_NONE,
  BITFIELD(18, 4) /* index 889 */,
  TILEGX_OPC_NONE, TILEGX_OPC_ROTLI, TILEGX_OPC_SHLI, TILEGX_OPC_SHLXI,
  TILEGX_OPC_SHRSI, TILEGX_OPC_SHRUI, TILEGX_OPC_SHRUXI, TILEGX_OPC_V1SHLI,
  TILEGX_OPC_V1SHRSI, TILEGX_OPC_V1SHRUI, TILEGX_OPC_V2SHLI,
  TILEGX_OPC_V2SHRSI, TILEGX_OPC_V2SHRUI, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE,
  BITFIELD(0, 2) /* index 906 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(911),
  BITFIELD(2, 2) /* index 911 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(916),
  BITFIELD(4, 2) /* index 916 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(921),
  BITFIELD(6, 2) /* index 921 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(926),
  BITFIELD(8, 2) /* index 926 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(931),
  BITFIELD(10, 2) /* index 931 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  TILEGX_OPC_INFOL,
};

static const unsigned short decode_X1_fsm[1266] =
{
  BITFIELD(53, 9) /* index 0 */,
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513), CHILD(513),
  CHILD(513), CHILD(513), CHILD(513), CHILD(513), TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI,
  TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_ADDXLI, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_BEQZT,
  TILEGX_OPC_BEQZT, TILEGX_OPC_BEQZ, TILEGX_OPC_BEQZ, TILEGX_OPC_BGEZT,
  TILEGX_OPC_BGEZT, TILEGX_OPC_BGEZ, TILEGX_OPC_BGEZ, TILEGX_OPC_BGTZT,
  TILEGX_OPC_BGTZT, TILEGX_OPC_BGTZ, TILEGX_OPC_BGTZ, TILEGX_OPC_BLBCT,
  TILEGX_OPC_BLBCT, TILEGX_OPC_BLBC, TILEGX_OPC_BLBC, TILEGX_OPC_BLBST,
  TILEGX_OPC_BLBST, TILEGX_OPC_BLBS, TILEGX_OPC_BLBS, TILEGX_OPC_BLEZT,
  TILEGX_OPC_BLEZT, TILEGX_OPC_BLEZ, TILEGX_OPC_BLEZ, TILEGX_OPC_BLTZT,
  TILEGX_OPC_BLTZT, TILEGX_OPC_BLTZ, TILEGX_OPC_BLTZ, TILEGX_OPC_BNEZT,
  TILEGX_OPC_BNEZT, TILEGX_OPC_BNEZ, TILEGX_OPC_BNEZ, CHILD(528), CHILD(578),
  CHILD(598), CHILD(703), CHILD(723), CHILD(728), CHILD(753), CHILD(758),
  CHILD(763), CHILD(768), CHILD(773), CHILD(778), TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL,
  TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_JAL, TILEGX_OPC_J, TILEGX_OPC_J,
  TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J,
  TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J,
  TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J,
  TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J,
  TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J,
  TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J, TILEGX_OPC_J,
  CHILD(783), CHILD(800), CHILD(832), CHILD(849), CHILD(1168), CHILD(1185),
  CHILD(1202), TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, CHILD(1219), TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236), CHILD(1236),
  CHILD(1236),
  BITFIELD(37, 2) /* index 513 */,
  TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, CHILD(518),
  BITFIELD(39, 2) /* index 518 */,
  TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, CHILD(523),
  BITFIELD(41, 2) /* index 523 */,
  TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_ADDLI, TILEGX_OPC_MOVELI,
  BITFIELD(51, 2) /* index 528 */,
  TILEGX_OPC_NONE, CHILD(533), TILEGX_OPC_ADDXI, CHILD(548),
  BITFIELD(37, 2) /* index 533 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(538),
  BITFIELD(39, 2) /* index 538 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(543),
  BITFIELD(41, 2) /* index 543 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_MOVEI,
  BITFIELD(31, 2) /* index 548 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(553),
  BITFIELD(33, 2) /* index 553 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(558),
  BITFIELD(35, 2) /* index 558 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(563),
  BITFIELD(37, 2) /* index 563 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(568),
  BITFIELD(39, 2) /* index 568 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(573),
  BITFIELD(41, 2) /* index 573 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_INFO,
  BITFIELD(51, 2) /* index 578 */,
  TILEGX_OPC_CMPEQI, TILEGX_OPC_CMPLTSI, TILEGX_OPC_CMPLTUI, CHILD(583),
  BITFIELD(31, 2) /* index 583 */,
  TILEGX_OPC_LD1S_ADD, TILEGX_OPC_LD1S_ADD, TILEGX_OPC_LD1S_ADD, CHILD(588),
  BITFIELD(33, 2) /* index 588 */,
  TILEGX_OPC_LD1S_ADD, TILEGX_OPC_LD1S_ADD, TILEGX_OPC_LD1S_ADD, CHILD(593),
  BITFIELD(35, 2) /* index 593 */,
  TILEGX_OPC_LD1S_ADD, TILEGX_OPC_LD1S_ADD, TILEGX_OPC_LD1S_ADD,
  TILEGX_OPC_PREFETCH_ADD_L1_FAULT,
  BITFIELD(51, 2) /* index 598 */,
  CHILD(603), CHILD(618), CHILD(633), CHILD(648),
  BITFIELD(31, 2) /* index 603 */,
  TILEGX_OPC_LD1U_ADD, TILEGX_OPC_LD1U_ADD, TILEGX_OPC_LD1U_ADD, CHILD(608),
  BITFIELD(33, 2) /* index 608 */,
  TILEGX_OPC_LD1U_ADD, TILEGX_OPC_LD1U_ADD, TILEGX_OPC_LD1U_ADD, CHILD(613),
  BITFIELD(35, 2) /* index 613 */,
  TILEGX_OPC_LD1U_ADD, TILEGX_OPC_LD1U_ADD, TILEGX_OPC_LD1U_ADD,
  TILEGX_OPC_PREFETCH_ADD_L1,
  BITFIELD(31, 2) /* index 618 */,
  TILEGX_OPC_LD2S_ADD, TILEGX_OPC_LD2S_ADD, TILEGX_OPC_LD2S_ADD, CHILD(623),
  BITFIELD(33, 2) /* index 623 */,
  TILEGX_OPC_LD2S_ADD, TILEGX_OPC_LD2S_ADD, TILEGX_OPC_LD2S_ADD, CHILD(628),
  BITFIELD(35, 2) /* index 628 */,
  TILEGX_OPC_LD2S_ADD, TILEGX_OPC_LD2S_ADD, TILEGX_OPC_LD2S_ADD,
  TILEGX_OPC_PREFETCH_ADD_L2_FAULT,
  BITFIELD(31, 2) /* index 633 */,
  TILEGX_OPC_LD2U_ADD, TILEGX_OPC_LD2U_ADD, TILEGX_OPC_LD2U_ADD, CHILD(638),
  BITFIELD(33, 2) /* index 638 */,
  TILEGX_OPC_LD2U_ADD, TILEGX_OPC_LD2U_ADD, TILEGX_OPC_LD2U_ADD, CHILD(643),
  BITFIELD(35, 2) /* index 643 */,
  TILEGX_OPC_LD2U_ADD, TILEGX_OPC_LD2U_ADD, TILEGX_OPC_LD2U_ADD,
  TILEGX_OPC_PREFETCH_ADD_L2,
  BITFIELD(31, 2) /* index 648 */,
  CHILD(653), CHILD(653), CHILD(653), CHILD(673),
  BITFIELD(43, 2) /* index 653 */,
  CHILD(658), TILEGX_OPC_LD4S_ADD, TILEGX_OPC_LD4S_ADD, TILEGX_OPC_LD4S_ADD,
  BITFIELD(45, 2) /* index 658 */,
  CHILD(663), TILEGX_OPC_LD4S_ADD, TILEGX_OPC_LD4S_ADD, TILEGX_OPC_LD4S_ADD,
  BITFIELD(47, 2) /* index 663 */,
  CHILD(668), TILEGX_OPC_LD4S_ADD, TILEGX_OPC_LD4S_ADD, TILEGX_OPC_LD4S_ADD,
  BITFIELD(49, 2) /* index 668 */,
  TILEGX_OPC_LD4S_TLS, TILEGX_OPC_LD4S_ADD, TILEGX_OPC_LD4S_ADD,
  TILEGX_OPC_LD4S_ADD,
  BITFIELD(33, 2) /* index 673 */,
  CHILD(653), CHILD(653), CHILD(653), CHILD(678),
  BITFIELD(35, 2) /* index 678 */,
  CHILD(653), CHILD(653), CHILD(653), CHILD(683),
  BITFIELD(43, 2) /* index 683 */,
  CHILD(688), TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  TILEGX_OPC_PREFETCH_ADD_L3_FAULT, TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  BITFIELD(45, 2) /* index 688 */,
  CHILD(693), TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  TILEGX_OPC_PREFETCH_ADD_L3_FAULT, TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  BITFIELD(47, 2) /* index 693 */,
  CHILD(698), TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  TILEGX_OPC_PREFETCH_ADD_L3_FAULT, TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  BITFIELD(49, 2) /* index 698 */,
  TILEGX_OPC_LD4S_TLS, TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  TILEGX_OPC_PREFETCH_ADD_L3_FAULT, TILEGX_OPC_PREFETCH_ADD_L3_FAULT,
  BITFIELD(51, 2) /* index 703 */,
  CHILD(708), TILEGX_OPC_LDNT1S_ADD, TILEGX_OPC_LDNT1U_ADD,
  TILEGX_OPC_LDNT2S_ADD,
  BITFIELD(31, 2) /* index 708 */,
  TILEGX_OPC_LD4U_ADD, TILEGX_OPC_LD4U_ADD, TILEGX_OPC_LD4U_ADD, CHILD(713),
  BITFIELD(33, 2) /* index 713 */,
  TILEGX_OPC_LD4U_ADD, TILEGX_OPC_LD4U_ADD, TILEGX_OPC_LD4U_ADD, CHILD(718),
  BITFIELD(35, 2) /* index 718 */,
  TILEGX_OPC_LD4U_ADD, TILEGX_OPC_LD4U_ADD, TILEGX_OPC_LD4U_ADD,
  TILEGX_OPC_PREFETCH_ADD_L3,
  BITFIELD(51, 2) /* index 723 */,
  TILEGX_OPC_LDNT2U_ADD, TILEGX_OPC_LDNT4S_ADD, TILEGX_OPC_LDNT4U_ADD,
  TILEGX_OPC_LDNT_ADD,
  BITFIELD(51, 2) /* index 728 */,
  CHILD(733), TILEGX_OPC_LDNA_ADD, TILEGX_OPC_MFSPR, TILEGX_OPC_MTSPR,
  BITFIELD(43, 2) /* index 733 */,
  CHILD(738), TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD,
  BITFIELD(45, 2) /* index 738 */,
  CHILD(743), TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD,
  BITFIELD(47, 2) /* index 743 */,
  CHILD(748), TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD,
  BITFIELD(49, 2) /* index 748 */,
  TILEGX_OPC_LD_TLS, TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD, TILEGX_OPC_LD_ADD,
  BITFIELD(51, 2) /* index 753 */,
  TILEGX_OPC_ORI, TILEGX_OPC_ST1_ADD, TILEGX_OPC_ST2_ADD, TILEGX_OPC_ST4_ADD,
  BITFIELD(51, 2) /* index 758 */,
  TILEGX_OPC_STNT1_ADD, TILEGX_OPC_STNT2_ADD, TILEGX_OPC_STNT4_ADD,
  TILEGX_OPC_STNT_ADD,
  BITFIELD(51, 2) /* index 763 */,
  TILEGX_OPC_ST_ADD, TILEGX_OPC_V1ADDI, TILEGX_OPC_V1CMPEQI,
  TILEGX_OPC_V1CMPLTSI,
  BITFIELD(51, 2) /* index 768 */,
  TILEGX_OPC_V1CMPLTUI, TILEGX_OPC_V1MAXUI, TILEGX_OPC_V1MINUI,
  TILEGX_OPC_V2ADDI,
  BITFIELD(51, 2) /* index 773 */,
  TILEGX_OPC_V2CMPEQI, TILEGX_OPC_V2CMPLTSI, TILEGX_OPC_V2CMPLTUI,
  TILEGX_OPC_V2MAXSI,
  BITFIELD(51, 2) /* index 778 */,
  TILEGX_OPC_V2MINSI, TILEGX_OPC_XORI, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(49, 4) /* index 783 */,
  TILEGX_OPC_NONE, TILEGX_OPC_ADDXSC, TILEGX_OPC_ADDX, TILEGX_OPC_ADD,
  TILEGX_OPC_AND, TILEGX_OPC_CMPEQ, TILEGX_OPC_CMPEXCH4, TILEGX_OPC_CMPEXCH,
  TILEGX_OPC_CMPLES, TILEGX_OPC_CMPLEU, TILEGX_OPC_CMPLTS, TILEGX_OPC_CMPLTU,
  TILEGX_OPC_CMPNE, TILEGX_OPC_DBLALIGN2, TILEGX_OPC_DBLALIGN4,
  TILEGX_OPC_DBLALIGN6,
  BITFIELD(49, 4) /* index 800 */,
  TILEGX_OPC_EXCH4, TILEGX_OPC_EXCH, TILEGX_OPC_FETCHADD4,
  TILEGX_OPC_FETCHADDGEZ4, TILEGX_OPC_FETCHADDGEZ, TILEGX_OPC_FETCHADD,
  TILEGX_OPC_FETCHAND4, TILEGX_OPC_FETCHAND, TILEGX_OPC_FETCHOR4,
  TILEGX_OPC_FETCHOR, TILEGX_OPC_MNZ, TILEGX_OPC_MZ, TILEGX_OPC_NOR,
  CHILD(817), TILEGX_OPC_ROTL, TILEGX_OPC_SHL1ADDX,
  BITFIELD(43, 2) /* index 817 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(822),
  BITFIELD(45, 2) /* index 822 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(827),
  BITFIELD(47, 2) /* index 827 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_MOVE,
  BITFIELD(49, 4) /* index 832 */,
  TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL2ADDX, TILEGX_OPC_SHL2ADD,
  TILEGX_OPC_SHL3ADDX, TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHLX, TILEGX_OPC_SHL,
  TILEGX_OPC_SHRS, TILEGX_OPC_SHRUX, TILEGX_OPC_SHRU, TILEGX_OPC_ST1,
  TILEGX_OPC_ST2, TILEGX_OPC_ST4, TILEGX_OPC_STNT1, TILEGX_OPC_STNT2,
  TILEGX_OPC_STNT4,
  BITFIELD(46, 7) /* index 849 */,
  TILEGX_OPC_STNT, TILEGX_OPC_STNT, TILEGX_OPC_STNT, TILEGX_OPC_STNT,
  TILEGX_OPC_STNT, TILEGX_OPC_STNT, TILEGX_OPC_STNT, TILEGX_OPC_STNT,
  TILEGX_OPC_ST, TILEGX_OPC_ST, TILEGX_OPC_ST, TILEGX_OPC_ST, TILEGX_OPC_ST,
  TILEGX_OPC_ST, TILEGX_OPC_ST, TILEGX_OPC_ST, TILEGX_OPC_SUBXSC,
  TILEGX_OPC_SUBXSC, TILEGX_OPC_SUBXSC, TILEGX_OPC_SUBXSC, TILEGX_OPC_SUBXSC,
  TILEGX_OPC_SUBXSC, TILEGX_OPC_SUBXSC, TILEGX_OPC_SUBXSC, TILEGX_OPC_SUBX,
  TILEGX_OPC_SUBX, TILEGX_OPC_SUBX, TILEGX_OPC_SUBX, TILEGX_OPC_SUBX,
  TILEGX_OPC_SUBX, TILEGX_OPC_SUBX, TILEGX_OPC_SUBX, TILEGX_OPC_SUB,
  TILEGX_OPC_SUB, TILEGX_OPC_SUB, TILEGX_OPC_SUB, TILEGX_OPC_SUB,
  TILEGX_OPC_SUB, TILEGX_OPC_SUB, TILEGX_OPC_SUB, CHILD(978), CHILD(987),
  CHILD(1066), CHILD(1150), CHILD(1159), TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_V1ADDUC, TILEGX_OPC_V1ADDUC, TILEGX_OPC_V1ADDUC,
  TILEGX_OPC_V1ADDUC, TILEGX_OPC_V1ADDUC, TILEGX_OPC_V1ADDUC,
  TILEGX_OPC_V1ADDUC, TILEGX_OPC_V1ADDUC, TILEGX_OPC_V1ADD, TILEGX_OPC_V1ADD,
  TILEGX_OPC_V1ADD, TILEGX_OPC_V1ADD, TILEGX_OPC_V1ADD, TILEGX_OPC_V1ADD,
  TILEGX_OPC_V1ADD, TILEGX_OPC_V1ADD, TILEGX_OPC_V1CMPEQ, TILEGX_OPC_V1CMPEQ,
  TILEGX_OPC_V1CMPEQ, TILEGX_OPC_V1CMPEQ, TILEGX_OPC_V1CMPEQ,
  TILEGX_OPC_V1CMPEQ, TILEGX_OPC_V1CMPEQ, TILEGX_OPC_V1CMPEQ,
  TILEGX_OPC_V1CMPLES, TILEGX_OPC_V1CMPLES, TILEGX_OPC_V1CMPLES,
  TILEGX_OPC_V1CMPLES, TILEGX_OPC_V1CMPLES, TILEGX_OPC_V1CMPLES,
  TILEGX_OPC_V1CMPLES, TILEGX_OPC_V1CMPLES, TILEGX_OPC_V1CMPLEU,
  TILEGX_OPC_V1CMPLEU, TILEGX_OPC_V1CMPLEU, TILEGX_OPC_V1CMPLEU,
  TILEGX_OPC_V1CMPLEU, TILEGX_OPC_V1CMPLEU, TILEGX_OPC_V1CMPLEU,
  TILEGX_OPC_V1CMPLEU, TILEGX_OPC_V1CMPLTS, TILEGX_OPC_V1CMPLTS,
  TILEGX_OPC_V1CMPLTS, TILEGX_OPC_V1CMPLTS, TILEGX_OPC_V1CMPLTS,
  TILEGX_OPC_V1CMPLTS, TILEGX_OPC_V1CMPLTS, TILEGX_OPC_V1CMPLTS,
  TILEGX_OPC_V1CMPLTU, TILEGX_OPC_V1CMPLTU, TILEGX_OPC_V1CMPLTU,
  TILEGX_OPC_V1CMPLTU, TILEGX_OPC_V1CMPLTU, TILEGX_OPC_V1CMPLTU,
  TILEGX_OPC_V1CMPLTU, TILEGX_OPC_V1CMPLTU, TILEGX_OPC_V1CMPNE,
  TILEGX_OPC_V1CMPNE, TILEGX_OPC_V1CMPNE, TILEGX_OPC_V1CMPNE,
  TILEGX_OPC_V1CMPNE, TILEGX_OPC_V1CMPNE, TILEGX_OPC_V1CMPNE,
  TILEGX_OPC_V1CMPNE, TILEGX_OPC_V1INT_H, TILEGX_OPC_V1INT_H,
  TILEGX_OPC_V1INT_H, TILEGX_OPC_V1INT_H, TILEGX_OPC_V1INT_H,
  TILEGX_OPC_V1INT_H, TILEGX_OPC_V1INT_H, TILEGX_OPC_V1INT_H,
  TILEGX_OPC_V1INT_L, TILEGX_OPC_V1INT_L, TILEGX_OPC_V1INT_L,
  TILEGX_OPC_V1INT_L, TILEGX_OPC_V1INT_L, TILEGX_OPC_V1INT_L,
  TILEGX_OPC_V1INT_L, TILEGX_OPC_V1INT_L,
  BITFIELD(43, 3) /* index 978 */,
  TILEGX_OPC_NONE, TILEGX_OPC_DRAIN, TILEGX_OPC_DTLBPR, TILEGX_OPC_FINV,
  TILEGX_OPC_FLUSHWB, TILEGX_OPC_FLUSH, TILEGX_OPC_FNOP, TILEGX_OPC_ICOH,
  BITFIELD(43, 3) /* index 987 */,
  CHILD(996), TILEGX_OPC_INV, TILEGX_OPC_IRET, TILEGX_OPC_JALRP,
  TILEGX_OPC_JALR, TILEGX_OPC_JRP, TILEGX_OPC_JR, CHILD(1051),
  BITFIELD(31, 2) /* index 996 */,
  CHILD(1001), CHILD(1026), TILEGX_OPC_ILL, TILEGX_OPC_ILL,
  BITFIELD(33, 2) /* index 1001 */,
  TILEGX_OPC_ILL, TILEGX_OPC_ILL, TILEGX_OPC_ILL, CHILD(1006),
  BITFIELD(35, 2) /* index 1006 */,
  TILEGX_OPC_ILL, CHILD(1011), TILEGX_OPC_ILL, TILEGX_OPC_ILL,
  BITFIELD(37, 2) /* index 1011 */,
  TILEGX_OPC_ILL, CHILD(1016), TILEGX_OPC_ILL, TILEGX_OPC_ILL,
  BITFIELD(39, 2) /* index 1016 */,
  TILEGX_OPC_ILL, CHILD(1021), TILEGX_OPC_ILL, TILEGX_OPC_ILL,
  BITFIELD(41, 2) /* index 1021 */,
  TILEGX_OPC_ILL, TILEGX_OPC_ILL, TILEGX_OPC_BPT, TILEGX_OPC_ILL,
  BITFIELD(33, 2) /* index 1026 */,
  TILEGX_OPC_ILL, TILEGX_OPC_ILL, TILEGX_OPC_ILL, CHILD(1031),
  BITFIELD(35, 2) /* index 1031 */,
  TILEGX_OPC_ILL, CHILD(1036), TILEGX_OPC_ILL, TILEGX_OPC_ILL,
  BITFIELD(37, 2) /* index 1036 */,
  TILEGX_OPC_ILL, CHILD(1041), TILEGX_OPC_ILL, TILEGX_OPC_ILL,
  BITFIELD(39, 2) /* index 1041 */,
  TILEGX_OPC_ILL, CHILD(1046), TILEGX_OPC_ILL, TILEGX_OPC_ILL,
  BITFIELD(41, 2) /* index 1046 */,
  TILEGX_OPC_ILL, TILEGX_OPC_ILL, TILEGX_OPC_RAISE, TILEGX_OPC_ILL,
  BITFIELD(31, 2) /* index 1051 */,
  TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, CHILD(1056),
  BITFIELD(33, 2) /* index 1056 */,
  TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, CHILD(1061),
  BITFIELD(35, 2) /* index 1061 */,
  TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, TILEGX_OPC_LD1S,
  TILEGX_OPC_PREFETCH_L1_FAULT,
  BITFIELD(43, 3) /* index 1066 */,
  CHILD(1075), CHILD(1090), CHILD(1105), CHILD(1120), CHILD(1135),
  TILEGX_OPC_LDNA, TILEGX_OPC_LDNT1S, TILEGX_OPC_LDNT1U,
  BITFIELD(31, 2) /* index 1075 */,
  TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, CHILD(1080),
  BITFIELD(33, 2) /* index 1080 */,
  TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, CHILD(1085),
  BITFIELD(35, 2) /* index 1085 */,
  TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, TILEGX_OPC_PREFETCH,
  BITFIELD(31, 2) /* index 1090 */,
  TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, CHILD(1095),
  BITFIELD(33, 2) /* index 1095 */,
  TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, CHILD(1100),
  BITFIELD(35, 2) /* index 1100 */,
  TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, TILEGX_OPC_LD2S,
  TILEGX_OPC_PREFETCH_L2_FAULT,
  BITFIELD(31, 2) /* index 1105 */,
  TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, CHILD(1110),
  BITFIELD(33, 2) /* index 1110 */,
  TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, CHILD(1115),
  BITFIELD(35, 2) /* index 1115 */,
  TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, TILEGX_OPC_PREFETCH_L2,
  BITFIELD(31, 2) /* index 1120 */,
  TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, CHILD(1125),
  BITFIELD(33, 2) /* index 1125 */,
  TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, CHILD(1130),
  BITFIELD(35, 2) /* index 1130 */,
  TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, TILEGX_OPC_LD4S,
  TILEGX_OPC_PREFETCH_L3_FAULT,
  BITFIELD(31, 2) /* index 1135 */,
  TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, CHILD(1140),
  BITFIELD(33, 2) /* index 1140 */,
  TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, CHILD(1145),
  BITFIELD(35, 2) /* index 1145 */,
  TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, TILEGX_OPC_PREFETCH_L3,
  BITFIELD(43, 3) /* index 1150 */,
  TILEGX_OPC_LDNT2S, TILEGX_OPC_LDNT2U, TILEGX_OPC_LDNT4S, TILEGX_OPC_LDNT4U,
  TILEGX_OPC_LDNT, TILEGX_OPC_LD, TILEGX_OPC_LNK, TILEGX_OPC_MF,
  BITFIELD(43, 3) /* index 1159 */,
  TILEGX_OPC_NAP, TILEGX_OPC_NOP, TILEGX_OPC_SWINT0, TILEGX_OPC_SWINT1,
  TILEGX_OPC_SWINT2, TILEGX_OPC_SWINT3, TILEGX_OPC_WH64, TILEGX_OPC_NONE,
  BITFIELD(49, 4) /* index 1168 */,
  TILEGX_OPC_V1MAXU, TILEGX_OPC_V1MINU, TILEGX_OPC_V1MNZ, TILEGX_OPC_V1MZ,
  TILEGX_OPC_V1SHL, TILEGX_OPC_V1SHRS, TILEGX_OPC_V1SHRU, TILEGX_OPC_V1SUBUC,
  TILEGX_OPC_V1SUB, TILEGX_OPC_V2ADDSC, TILEGX_OPC_V2ADD, TILEGX_OPC_V2CMPEQ,
  TILEGX_OPC_V2CMPLES, TILEGX_OPC_V2CMPLEU, TILEGX_OPC_V2CMPLTS,
  TILEGX_OPC_V2CMPLTU,
  BITFIELD(49, 4) /* index 1185 */,
  TILEGX_OPC_V2CMPNE, TILEGX_OPC_V2INT_H, TILEGX_OPC_V2INT_L,
  TILEGX_OPC_V2MAXS, TILEGX_OPC_V2MINS, TILEGX_OPC_V2MNZ, TILEGX_OPC_V2MZ,
  TILEGX_OPC_V2PACKH, TILEGX_OPC_V2PACKL, TILEGX_OPC_V2PACKUC,
  TILEGX_OPC_V2SHLSC, TILEGX_OPC_V2SHL, TILEGX_OPC_V2SHRS, TILEGX_OPC_V2SHRU,
  TILEGX_OPC_V2SUBSC, TILEGX_OPC_V2SUB,
  BITFIELD(49, 4) /* index 1202 */,
  TILEGX_OPC_V4ADDSC, TILEGX_OPC_V4ADD, TILEGX_OPC_V4INT_H,
  TILEGX_OPC_V4INT_L, TILEGX_OPC_V4PACKSC, TILEGX_OPC_V4SHLSC,
  TILEGX_OPC_V4SHL, TILEGX_OPC_V4SHRS, TILEGX_OPC_V4SHRU, TILEGX_OPC_V4SUBSC,
  TILEGX_OPC_V4SUB, TILEGX_OPC_XOR, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(49, 4) /* index 1219 */,
  TILEGX_OPC_NONE, TILEGX_OPC_ROTLI, TILEGX_OPC_SHLI, TILEGX_OPC_SHLXI,
  TILEGX_OPC_SHRSI, TILEGX_OPC_SHRUI, TILEGX_OPC_SHRUXI, TILEGX_OPC_V1SHLI,
  TILEGX_OPC_V1SHRSI, TILEGX_OPC_V1SHRUI, TILEGX_OPC_V2SHLI,
  TILEGX_OPC_V2SHRSI, TILEGX_OPC_V2SHRUI, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE,
  BITFIELD(31, 2) /* index 1236 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(1241),
  BITFIELD(33, 2) /* index 1241 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(1246),
  BITFIELD(35, 2) /* index 1246 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(1251),
  BITFIELD(37, 2) /* index 1251 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(1256),
  BITFIELD(39, 2) /* index 1256 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  CHILD(1261),
  BITFIELD(41, 2) /* index 1261 */,
  TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI, TILEGX_OPC_SHL16INSLI,
  TILEGX_OPC_INFOL,
};

static const unsigned short decode_Y0_fsm[178] =
{
  BITFIELD(27, 4) /* index 0 */,
  CHILD(17), TILEGX_OPC_ADDXI, CHILD(32), TILEGX_OPC_CMPEQI,
  TILEGX_OPC_CMPLTSI, CHILD(62), CHILD(67), CHILD(118), CHILD(123),
  CHILD(128), CHILD(133), CHILD(153), CHILD(158), CHILD(163), CHILD(168),
  CHILD(173),
  BITFIELD(6, 2) /* index 17 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(22),
  BITFIELD(8, 2) /* index 22 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(27),
  BITFIELD(10, 2) /* index 27 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_MOVEI,
  BITFIELD(0, 2) /* index 32 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(37),
  BITFIELD(2, 2) /* index 37 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(42),
  BITFIELD(4, 2) /* index 42 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(47),
  BITFIELD(6, 2) /* index 47 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(52),
  BITFIELD(8, 2) /* index 52 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(57),
  BITFIELD(10, 2) /* index 57 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_INFO,
  BITFIELD(18, 2) /* index 62 */,
  TILEGX_OPC_ADDX, TILEGX_OPC_ADD, TILEGX_OPC_SUBX, TILEGX_OPC_SUB,
  BITFIELD(15, 5) /* index 67 */,
  TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL1ADD,
  TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL1ADD,
  TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL2ADD,
  TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL2ADD,
  TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL2ADD,
  TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHL3ADD,
  TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHL3ADD,
  TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHL3ADD, CHILD(100),
  CHILD(109), TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(12, 3) /* index 100 */,
  TILEGX_OPC_NONE, TILEGX_OPC_CLZ, TILEGX_OPC_CTZ, TILEGX_OPC_FNOP,
  TILEGX_OPC_FSINGLE_PACK1, TILEGX_OPC_NOP, TILEGX_OPC_PCNT,
  TILEGX_OPC_REVBITS,
  BITFIELD(12, 3) /* index 109 */,
  TILEGX_OPC_REVBYTES, TILEGX_OPC_TBLIDXB0, TILEGX_OPC_TBLIDXB1,
  TILEGX_OPC_TBLIDXB2, TILEGX_OPC_TBLIDXB3, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  TILEGX_OPC_NONE,
  BITFIELD(18, 2) /* index 118 */,
  TILEGX_OPC_CMPLES, TILEGX_OPC_CMPLEU, TILEGX_OPC_CMPLTS, TILEGX_OPC_CMPLTU,
  BITFIELD(18, 2) /* index 123 */,
  TILEGX_OPC_CMPEQ, TILEGX_OPC_CMPNE, TILEGX_OPC_MULAX, TILEGX_OPC_MULX,
  BITFIELD(18, 2) /* index 128 */,
  TILEGX_OPC_CMOVEQZ, TILEGX_OPC_CMOVNEZ, TILEGX_OPC_MNZ, TILEGX_OPC_MZ,
  BITFIELD(18, 2) /* index 133 */,
  TILEGX_OPC_AND, TILEGX_OPC_NOR, CHILD(138), TILEGX_OPC_XOR,
  BITFIELD(12, 2) /* index 138 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(143),
  BITFIELD(14, 2) /* index 143 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(148),
  BITFIELD(16, 2) /* index 148 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_MOVE,
  BITFIELD(18, 2) /* index 153 */,
  TILEGX_OPC_ROTL, TILEGX_OPC_SHL, TILEGX_OPC_SHRS, TILEGX_OPC_SHRU,
  BITFIELD(18, 2) /* index 158 */,
  TILEGX_OPC_NONE, TILEGX_OPC_SHL1ADDX, TILEGX_OPC_SHL2ADDX,
  TILEGX_OPC_SHL3ADDX,
  BITFIELD(18, 2) /* index 163 */,
  TILEGX_OPC_MUL_HS_HS, TILEGX_OPC_MUL_HU_HU, TILEGX_OPC_MUL_LS_LS,
  TILEGX_OPC_MUL_LU_LU,
  BITFIELD(18, 2) /* index 168 */,
  TILEGX_OPC_MULA_HS_HS, TILEGX_OPC_MULA_HU_HU, TILEGX_OPC_MULA_LS_LS,
  TILEGX_OPC_MULA_LU_LU,
  BITFIELD(18, 2) /* index 173 */,
  TILEGX_OPC_ROTLI, TILEGX_OPC_SHLI, TILEGX_OPC_SHRSI, TILEGX_OPC_SHRUI,
};

static const unsigned short decode_Y1_fsm[167] =
{
  BITFIELD(58, 4) /* index 0 */,
  TILEGX_OPC_NONE, CHILD(17), TILEGX_OPC_ADDXI, CHILD(32), TILEGX_OPC_CMPEQI,
  TILEGX_OPC_CMPLTSI, CHILD(62), CHILD(67), CHILD(117), CHILD(122),
  CHILD(127), CHILD(132), CHILD(152), CHILD(157), CHILD(162), TILEGX_OPC_NONE,
  BITFIELD(37, 2) /* index 17 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(22),
  BITFIELD(39, 2) /* index 22 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, CHILD(27),
  BITFIELD(41, 2) /* index 27 */,
  TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_ADDI, TILEGX_OPC_MOVEI,
  BITFIELD(31, 2) /* index 32 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(37),
  BITFIELD(33, 2) /* index 37 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(42),
  BITFIELD(35, 2) /* index 42 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(47),
  BITFIELD(37, 2) /* index 47 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(52),
  BITFIELD(39, 2) /* index 52 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, CHILD(57),
  BITFIELD(41, 2) /* index 57 */,
  TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_ANDI, TILEGX_OPC_INFO,
  BITFIELD(49, 2) /* index 62 */,
  TILEGX_OPC_ADDX, TILEGX_OPC_ADD, TILEGX_OPC_SUBX, TILEGX_OPC_SUB,
  BITFIELD(47, 4) /* index 67 */,
  TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL1ADD,
  TILEGX_OPC_SHL1ADD, TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL2ADD,
  TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL2ADD, TILEGX_OPC_SHL3ADD,
  TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHL3ADD, TILEGX_OPC_SHL3ADD, CHILD(84),
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_NONE,
  BITFIELD(43, 3) /* index 84 */,
  CHILD(93), CHILD(96), CHILD(99), CHILD(102), CHILD(105), CHILD(108),
  CHILD(111), CHILD(114),
  BITFIELD(46, 1) /* index 93 */,
  TILEGX_OPC_NONE, TILEGX_OPC_FNOP,
  BITFIELD(46, 1) /* index 96 */,
  TILEGX_OPC_NONE, TILEGX_OPC_ILL,
  BITFIELD(46, 1) /* index 99 */,
  TILEGX_OPC_NONE, TILEGX_OPC_JALRP,
  BITFIELD(46, 1) /* index 102 */,
  TILEGX_OPC_NONE, TILEGX_OPC_JALR,
  BITFIELD(46, 1) /* index 105 */,
  TILEGX_OPC_NONE, TILEGX_OPC_JRP,
  BITFIELD(46, 1) /* index 108 */,
  TILEGX_OPC_NONE, TILEGX_OPC_JR,
  BITFIELD(46, 1) /* index 111 */,
  TILEGX_OPC_NONE, TILEGX_OPC_LNK,
  BITFIELD(46, 1) /* index 114 */,
  TILEGX_OPC_NONE, TILEGX_OPC_NOP,
  BITFIELD(49, 2) /* index 117 */,
  TILEGX_OPC_CMPLES, TILEGX_OPC_CMPLEU, TILEGX_OPC_CMPLTS, TILEGX_OPC_CMPLTU,
  BITFIELD(49, 2) /* index 122 */,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_CMPEQ, TILEGX_OPC_CMPNE,
  BITFIELD(49, 2) /* index 127 */,
  TILEGX_OPC_NONE, TILEGX_OPC_NONE, TILEGX_OPC_MNZ, TILEGX_OPC_MZ,
  BITFIELD(49, 2) /* index 132 */,
  TILEGX_OPC_AND, TILEGX_OPC_NOR, CHILD(137), TILEGX_OPC_XOR,
  BITFIELD(43, 2) /* index 137 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(142),
  BITFIELD(45, 2) /* index 142 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, CHILD(147),
  BITFIELD(47, 2) /* index 147 */,
  TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_OR, TILEGX_OPC_MOVE,
  BITFIELD(49, 2) /* index 152 */,
  TILEGX_OPC_ROTL, TILEGX_OPC_SHL, TILEGX_OPC_SHRS, TILEGX_OPC_SHRU,
  BITFIELD(49, 2) /* index 157 */,
  TILEGX_OPC_NONE, TILEGX_OPC_SHL1ADDX, TILEGX_OPC_SHL2ADDX,
  TILEGX_OPC_SHL3ADDX,
  BITFIELD(49, 2) /* index 162 */,
  TILEGX_OPC_ROTLI, TILEGX_OPC_SHLI, TILEGX_OPC_SHRSI, TILEGX_OPC_SHRUI,
};

static const unsigned short decode_Y2_fsm[118] =
{
  BITFIELD(62, 2) /* index 0 */,
  TILEGX_OPC_NONE, CHILD(5), CHILD(66), CHILD(109),
  BITFIELD(55, 3) /* index 5 */,
  CHILD(14), CHILD(14), CHILD(14), CHILD(17), CHILD(40), CHILD(40), CHILD(40),
  CHILD(43),
  BITFIELD(26, 1) /* index 14 */,
  TILEGX_OPC_LD1S, TILEGX_OPC_LD1U,
  BITFIELD(26, 1) /* index 17 */,
  CHILD(20), CHILD(30),
  BITFIELD(51, 2) /* index 20 */,
  TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, CHILD(25),
  BITFIELD(53, 2) /* index 25 */,
  TILEGX_OPC_LD1S, TILEGX_OPC_LD1S, TILEGX_OPC_LD1S,
  TILEGX_OPC_PREFETCH_L1_FAULT,
  BITFIELD(51, 2) /* index 30 */,
  TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, CHILD(35),
  BITFIELD(53, 2) /* index 35 */,
  TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, TILEGX_OPC_LD1U, TILEGX_OPC_PREFETCH,
  BITFIELD(26, 1) /* index 40 */,
  TILEGX_OPC_LD2S, TILEGX_OPC_LD2U,
  BITFIELD(26, 1) /* index 43 */,
  CHILD(46), CHILD(56),
  BITFIELD(51, 2) /* index 46 */,
  TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, CHILD(51),
  BITFIELD(53, 2) /* index 51 */,
  TILEGX_OPC_LD2S, TILEGX_OPC_LD2S, TILEGX_OPC_LD2S,
  TILEGX_OPC_PREFETCH_L2_FAULT,
  BITFIELD(51, 2) /* index 56 */,
  TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, CHILD(61),
  BITFIELD(53, 2) /* index 61 */,
  TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, TILEGX_OPC_LD2U, TILEGX_OPC_PREFETCH_L2,
  BITFIELD(56, 2) /* index 66 */,
  CHILD(71), CHILD(74), CHILD(90), CHILD(93),
  BITFIELD(26, 1) /* index 71 */,
  TILEGX_OPC_NONE, TILEGX_OPC_LD4S,
  BITFIELD(26, 1) /* index 74 */,
  TILEGX_OPC_NONE, CHILD(77),
  BITFIELD(51, 2) /* index 77 */,
  TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, CHILD(82),
  BITFIELD(53, 2) /* index 82 */,
  TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, TILEGX_OPC_LD4S, CHILD(87),
  BITFIELD(55, 1) /* index 87 */,
  TILEGX_OPC_LD4S, TILEGX_OPC_PREFETCH_L3_FAULT,
  BITFIELD(26, 1) /* index 90 */,
  TILEGX_OPC_LD4U, TILEGX_OPC_LD,
  BITFIELD(26, 1) /* index 93 */,
  CHILD(96), TILEGX_OPC_LD,
  BITFIELD(51, 2) /* index 96 */,
  TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, CHILD(101),
  BITFIELD(53, 2) /* index 101 */,
  TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, TILEGX_OPC_LD4U, CHILD(106),
  BITFIELD(55, 1) /* index 106 */,
  TILEGX_OPC_LD4U, TILEGX_OPC_PREFETCH_L3,
  BITFIELD(26, 1) /* index 109 */,
  CHILD(112), CHILD(115),
  BITFIELD(57, 1) /* index 112 */,
  TILEGX_OPC_ST1, TILEGX_OPC_ST4,
  BITFIELD(57, 1) /* index 115 */,
  TILEGX_OPC_ST2, TILEGX_OPC_ST,
};

#undef BITFIELD
#undef CHILD
const unsigned short * const
tilegx_bundle_decoder_fsms[TILEGX_NUM_PIPELINE_ENCODINGS] =
{
  decode_X0_fsm,
  decode_X1_fsm,
  decode_Y0_fsm,
  decode_Y1_fsm,
  decode_Y2_fsm
};
const struct tilegx_operand tilegx_operands[35] =
{
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_IMM8_X0),
    8, 1, 0, 0, 0, 0,
    create_Imm8_X0, get_Imm8_X0
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_IMM8_X1),
    8, 1, 0, 0, 0, 0,
    create_Imm8_X1, get_Imm8_X1
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_IMM8_Y0),
    8, 1, 0, 0, 0, 0,
    create_Imm8_Y0, get_Imm8_Y0
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_IMM8_Y1),
    8, 1, 0, 0, 0, 0,
    create_Imm8_Y1, get_Imm8_Y1
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_IMM16_X0_HW0_LAST),
    16, 1, 0, 0, 0, 0,
    create_Imm16_X0, get_Imm16_X0
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_IMM16_X1_HW0_LAST),
    16, 1, 0, 0, 0, 0,
    create_Imm16_X1, get_Imm16_X1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 0, 1, 0, 0,
    create_Dest_X1, get_Dest_X1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcA_X1, get_SrcA_X1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 0, 1, 0, 0,
    create_Dest_X0, get_Dest_X0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcA_X0, get_SrcA_X0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 0, 1, 0, 0,
    create_Dest_Y0, get_Dest_Y0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcA_Y0, get_SrcA_Y0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 0, 1, 0, 0,
    create_Dest_Y1, get_Dest_Y1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcA_Y1, get_SrcA_Y1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcA_Y2, get_SrcA_Y2
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 1, 0, 0,
    create_SrcA_X1, get_SrcA_X1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcB_X0, get_SrcB_X0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcB_X1, get_SrcB_X1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcB_Y0, get_SrcB_Y0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcB_Y1, get_SrcB_Y1
  },
  {
    TILEGX_OP_TYPE_ADDRESS, BFD_RELOC(TILEGX_BROFF_X1),
    17, 1, 0, 0, 1, TILEGX_LOG2_BUNDLE_ALIGNMENT_IN_BYTES,
    create_BrOff_X1, get_BrOff_X1
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_MMSTART_X0),
    6, 0, 0, 0, 0, 0,
    create_BFStart_X0, get_BFStart_X0
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_MMEND_X0),
    6, 0, 0, 0, 0, 0,
    create_BFEnd_X0, get_BFEnd_X0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 1, 0, 0,
    create_Dest_X0, get_Dest_X0
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 1, 0, 0,
    create_Dest_Y0, get_Dest_Y0
  },
  {
    TILEGX_OP_TYPE_ADDRESS, BFD_RELOC(TILEGX_JUMPOFF_X1),
    27, 1, 0, 0, 1, TILEGX_LOG2_BUNDLE_ALIGNMENT_IN_BYTES,
    create_JumpOff_X1, get_JumpOff_X1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 0, 1, 0, 0,
    create_SrcBDest_Y2, get_SrcBDest_Y2
  },
  {
    TILEGX_OP_TYPE_SPR, BFD_RELOC(TILEGX_MF_IMM14_X1),
    14, 0, 0, 0, 0, 0,
    create_MF_Imm14_X1, get_MF_Imm14_X1
  },
  {
    TILEGX_OP_TYPE_SPR, BFD_RELOC(TILEGX_MT_IMM14_X1),
    14, 0, 0, 0, 0, 0,
    create_MT_Imm14_X1, get_MT_Imm14_X1
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_SHAMT_X0),
    6, 0, 0, 0, 0, 0,
    create_ShAmt_X0, get_ShAmt_X0
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_SHAMT_X1),
    6, 0, 0, 0, 0, 0,
    create_ShAmt_X1, get_ShAmt_X1
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_SHAMT_Y0),
    6, 0, 0, 0, 0, 0,
    create_ShAmt_Y0, get_ShAmt_Y0
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_SHAMT_Y1),
    6, 0, 0, 0, 0, 0,
    create_ShAmt_Y1, get_ShAmt_Y1
  },
  {
    TILEGX_OP_TYPE_REGISTER, BFD_RELOC(NONE),
    6, 0, 1, 0, 0, 0,
    create_SrcBDest_Y2, get_SrcBDest_Y2
  },
  {
    TILEGX_OP_TYPE_IMMEDIATE, BFD_RELOC(TILEGX_DEST_IMM8_X1),
    8, 1, 0, 0, 0, 0,
    create_Dest_Imm8_X1, get_Dest_Imm8_X1
  }
};

#ifndef DISASM_ONLY
const struct tilegx_spr tilegx_sprs[] = {
  { 0, "MPL_MEM_ERROR_SET_0" },
  { 1, "MPL_MEM_ERROR_SET_1" },
  { 2, "MPL_MEM_ERROR_SET_2" },
  { 3, "MPL_MEM_ERROR_SET_3" },
  { 4, "MPL_MEM_ERROR" },
  { 5, "MEM_ERROR_CBOX_ADDR" },
  { 6, "MEM_ERROR_CBOX_STATUS" },
  { 7, "MEM_ERROR_ENABLE" },
  { 8, "MEM_ERROR_MBOX_ADDR" },
  { 9, "MEM_ERROR_MBOX_STATUS" },
  { 10, "SBOX_ERROR" },
  { 11, "XDN_DEMUX_ERROR" },
  { 256, "MPL_SINGLE_STEP_3_SET_0" },
  { 257, "MPL_SINGLE_STEP_3_SET_1" },
  { 258, "MPL_SINGLE_STEP_3_SET_2" },
  { 259, "MPL_SINGLE_STEP_3_SET_3" },
  { 260, "MPL_SINGLE_STEP_3" },
  { 261, "SINGLE_STEP_CONTROL_3" },
  { 512, "MPL_SINGLE_STEP_2_SET_0" },
  { 513, "MPL_SINGLE_STEP_2_SET_1" },
  { 514, "MPL_SINGLE_STEP_2_SET_2" },
  { 515, "MPL_SINGLE_STEP_2_SET_3" },
  { 516, "MPL_SINGLE_STEP_2" },
  { 517, "SINGLE_STEP_CONTROL_2" },
  { 768, "MPL_SINGLE_STEP_1_SET_0" },
  { 769, "MPL_SINGLE_STEP_1_SET_1" },
  { 770, "MPL_SINGLE_STEP_1_SET_2" },
  { 771, "MPL_SINGLE_STEP_1_SET_3" },
  { 772, "MPL_SINGLE_STEP_1" },
  { 773, "SINGLE_STEP_CONTROL_1" },
  { 1024, "MPL_SINGLE_STEP_0_SET_0" },
  { 1025, "MPL_SINGLE_STEP_0_SET_1" },
  { 1026, "MPL_SINGLE_STEP_0_SET_2" },
  { 1027, "MPL_SINGLE_STEP_0_SET_3" },
  { 1028, "MPL_SINGLE_STEP_0" },
  { 1029, "SINGLE_STEP_CONTROL_0" },
  { 1280, "MPL_IDN_COMPLETE_SET_0" },
  { 1281, "MPL_IDN_COMPLETE_SET_1" },
  { 1282, "MPL_IDN_COMPLETE_SET_2" },
  { 1283, "MPL_IDN_COMPLETE_SET_3" },
  { 1284, "MPL_IDN_COMPLETE" },
  { 1285, "IDN_COMPLETE_PENDING" },
  { 1536, "MPL_UDN_COMPLETE_SET_0" },
  { 1537, "MPL_UDN_COMPLETE_SET_1" },
  { 1538, "MPL_UDN_COMPLETE_SET_2" },
  { 1539, "MPL_UDN_COMPLETE_SET_3" },
  { 1540, "MPL_UDN_COMPLETE" },
  { 1541, "UDN_COMPLETE_PENDING" },
  { 1792, "MPL_ITLB_MISS_SET_0" },
  { 1793, "MPL_ITLB_MISS_SET_1" },
  { 1794, "MPL_ITLB_MISS_SET_2" },
  { 1795, "MPL_ITLB_MISS_SET_3" },
  { 1796, "MPL_ITLB_MISS" },
  { 1797, "ITLB_TSB_BASE_ADDR_0" },
  { 1798, "ITLB_TSB_BASE_ADDR_1" },
  { 1920, "ITLB_CURRENT_ATTR" },
  { 1921, "ITLB_CURRENT_PA" },
  { 1922, "ITLB_CURRENT_VA" },
  { 1923, "ITLB_INDEX" },
  { 1924, "ITLB_MATCH_0" },
  { 1925, "ITLB_PERF" },
  { 1926, "ITLB_PR" },
  { 1927, "ITLB_TSB_ADDR_0" },
  { 1928, "ITLB_TSB_ADDR_1" },
  { 1929, "ITLB_TSB_FILL_CURRENT_ATTR" },
  { 1930, "ITLB_TSB_FILL_MATCH" },
  { 1931, "NUMBER_ITLB" },
  { 1932, "REPLACEMENT_ITLB" },
  { 1933, "WIRED_ITLB" },
  { 2048, "MPL_ILL_SET_0" },
  { 2049, "MPL_ILL_SET_1" },
  { 2050, "MPL_ILL_SET_2" },
  { 2051, "MPL_ILL_SET_3" },
  { 2052, "MPL_ILL" },
  { 2304, "MPL_GPV_SET_0" },
  { 2305, "MPL_GPV_SET_1" },
  { 2306, "MPL_GPV_SET_2" },
  { 2307, "MPL_GPV_SET_3" },
  { 2308, "MPL_GPV" },
  { 2309, "GPV_REASON" },
  { 2560, "MPL_IDN_ACCESS_SET_0" },
  { 2561, "MPL_IDN_ACCESS_SET_1" },
  { 2562, "MPL_IDN_ACCESS_SET_2" },
  { 2563, "MPL_IDN_ACCESS_SET_3" },
  { 2564, "MPL_IDN_ACCESS" },
  { 2565, "IDN_DEMUX_COUNT_0" },
  { 2566, "IDN_DEMUX_COUNT_1" },
  { 2567, "IDN_FLUSH_EGRESS" },
  { 2568, "IDN_PENDING" },
  { 2569, "IDN_ROUTE_ORDER" },
  { 2570, "IDN_SP_FIFO_CNT" },
  { 2688, "IDN_DATA_AVAIL" },
  { 2816, "MPL_UDN_ACCESS_SET_0" },
  { 2817, "MPL_UDN_ACCESS_SET_1" },
  { 2818, "MPL_UDN_ACCESS_SET_2" },
  { 2819, "MPL_UDN_ACCESS_SET_3" },
  { 2820, "MPL_UDN_ACCESS" },
  { 2821, "UDN_DEMUX_COUNT_0" },
  { 2822, "UDN_DEMUX_COUNT_1" },
  { 2823, "UDN_DEMUX_COUNT_2" },
  { 2824, "UDN_DEMUX_COUNT_3" },
  { 2825, "UDN_FLUSH_EGRESS" },
  { 2826, "UDN_PENDING" },
  { 2827, "UDN_ROUTE_ORDER" },
  { 2828, "UDN_SP_FIFO_CNT" },
  { 2944, "UDN_DATA_AVAIL" },
  { 3072, "MPL_SWINT_3_SET_0" },
  { 3073, "MPL_SWINT_3_SET_1" },
  { 3074, "MPL_SWINT_3_SET_2" },
  { 3075, "MPL_SWINT_3_SET_3" },
  { 3076, "MPL_SWINT_3" },
  { 3328, "MPL_SWINT_2_SET_0" },
  { 3329, "MPL_SWINT_2_SET_1" },
  { 3330, "MPL_SWINT_2_SET_2" },
  { 3331, "MPL_SWINT_2_SET_3" },
  { 3332, "MPL_SWINT_2" },
  { 3584, "MPL_SWINT_1_SET_0" },
  { 3585, "MPL_SWINT_1_SET_1" },
  { 3586, "MPL_SWINT_1_SET_2" },
  { 3587, "MPL_SWINT_1_SET_3" },
  { 3588, "MPL_SWINT_1" },
  { 3840, "MPL_SWINT_0_SET_0" },
  { 3841, "MPL_SWINT_0_SET_1" },
  { 3842, "MPL_SWINT_0_SET_2" },
  { 3843, "MPL_SWINT_0_SET_3" },
  { 3844, "MPL_SWINT_0" },
  { 4096, "MPL_ILL_TRANS_SET_0" },
  { 4097, "MPL_ILL_TRANS_SET_1" },
  { 4098, "MPL_ILL_TRANS_SET_2" },
  { 4099, "MPL_ILL_TRANS_SET_3" },
  { 4100, "MPL_ILL_TRANS" },
  { 4101, "ILL_TRANS_REASON" },
  { 4102, "ILL_VA_PC" },
  { 4352, "MPL_UNALIGN_DATA_SET_0" },
  { 4353, "MPL_UNALIGN_DATA_SET_1" },
  { 4354, "MPL_UNALIGN_DATA_SET_2" },
  { 4355, "MPL_UNALIGN_DATA_SET_3" },
  { 4356, "MPL_UNALIGN_DATA" },
  { 4608, "MPL_DTLB_MISS_SET_0" },
  { 4609, "MPL_DTLB_MISS_SET_1" },
  { 4610, "MPL_DTLB_MISS_SET_2" },
  { 4611, "MPL_DTLB_MISS_SET_3" },
  { 4612, "MPL_DTLB_MISS" },
  { 4613, "DTLB_TSB_BASE_ADDR_0" },
  { 4614, "DTLB_TSB_BASE_ADDR_1" },
  { 4736, "AAR" },
  { 4737, "CACHE_PINNED_WAYS" },
  { 4738, "DTLB_BAD_ADDR" },
  { 4739, "DTLB_BAD_ADDR_REASON" },
  { 4740, "DTLB_CURRENT_ATTR" },
  { 4741, "DTLB_CURRENT_PA" },
  { 4742, "DTLB_CURRENT_VA" },
  { 4743, "DTLB_INDEX" },
  { 4744, "DTLB_MATCH_0" },
  { 4745, "DTLB_PERF" },
  { 4746, "DTLB_TSB_ADDR_0" },
  { 4747, "DTLB_TSB_ADDR_1" },
  { 4748, "DTLB_TSB_FILL_CURRENT_ATTR" },
  { 4749, "DTLB_TSB_FILL_MATCH" },
  { 4750, "NUMBER_DTLB" },
  { 4751, "REPLACEMENT_DTLB" },
  { 4752, "WIRED_DTLB" },
  { 4864, "MPL_DTLB_ACCESS_SET_0" },
  { 4865, "MPL_DTLB_ACCESS_SET_1" },
  { 4866, "MPL_DTLB_ACCESS_SET_2" },
  { 4867, "MPL_DTLB_ACCESS_SET_3" },
  { 4868, "MPL_DTLB_ACCESS" },
  { 5120, "MPL_IDN_FIREWALL_SET_0" },
  { 5121, "MPL_IDN_FIREWALL_SET_1" },
  { 5122, "MPL_IDN_FIREWALL_SET_2" },
  { 5123, "MPL_IDN_FIREWALL_SET_3" },
  { 5124, "MPL_IDN_FIREWALL" },
  { 5125, "IDN_DIRECTION_PROTECT" },
  { 5376, "MPL_UDN_FIREWALL_SET_0" },
  { 5377, "MPL_UDN_FIREWALL_SET_1" },
  { 5378, "MPL_UDN_FIREWALL_SET_2" },
  { 5379, "MPL_UDN_FIREWALL_SET_3" },
  { 5380, "MPL_UDN_FIREWALL" },
  { 5381, "UDN_DIRECTION_PROTECT" },
  { 5632, "MPL_TILE_TIMER_SET_0" },
  { 5633, "MPL_TILE_TIMER_SET_1" },
  { 5634, "MPL_TILE_TIMER_SET_2" },
  { 5635, "MPL_TILE_TIMER_SET_3" },
  { 5636, "MPL_TILE_TIMER" },
  { 5637, "TILE_TIMER_CONTROL" },
  { 5888, "MPL_AUX_TILE_TIMER_SET_0" },
  { 5889, "MPL_AUX_TILE_TIMER_SET_1" },
  { 5890, "MPL_AUX_TILE_TIMER_SET_2" },
  { 5891, "MPL_AUX_TILE_TIMER_SET_3" },
  { 5892, "MPL_AUX_TILE_TIMER" },
  { 5893, "AUX_TILE_TIMER_CONTROL" },
  { 6144, "MPL_IDN_TIMER_SET_0" },
  { 6145, "MPL_IDN_TIMER_SET_1" },
  { 6146, "MPL_IDN_TIMER_SET_2" },
  { 6147, "MPL_IDN_TIMER_SET_3" },
  { 6148, "MPL_IDN_TIMER" },
  { 6149, "IDN_DEADLOCK_COUNT" },
  { 6150, "IDN_DEADLOCK_TIMEOUT" },
  { 6400, "MPL_UDN_TIMER_SET_0" },
  { 6401, "MPL_UDN_TIMER_SET_1" },
  { 6402, "MPL_UDN_TIMER_SET_2" },
  { 6403, "MPL_UDN_TIMER_SET_3" },
  { 6404, "MPL_UDN_TIMER" },
  { 6405, "UDN_DEADLOCK_COUNT" },
  { 6406, "UDN_DEADLOCK_TIMEOUT" },
  { 6656, "MPL_IDN_AVAIL_SET_0" },
  { 6657, "MPL_IDN_AVAIL_SET_1" },
  { 6658, "MPL_IDN_AVAIL_SET_2" },
  { 6659, "MPL_IDN_AVAIL_SET_3" },
  { 6660, "MPL_IDN_AVAIL" },
  { 6661, "IDN_AVAIL_EN" },
  { 6912, "MPL_UDN_AVAIL_SET_0" },
  { 6913, "MPL_UDN_AVAIL_SET_1" },
  { 6914, "MPL_UDN_AVAIL_SET_2" },
  { 6915, "MPL_UDN_AVAIL_SET_3" },
  { 6916, "MPL_UDN_AVAIL" },
  { 6917, "UDN_AVAIL_EN" },
  { 7168, "MPL_IPI_3_SET_0" },
  { 7169, "MPL_IPI_3_SET_1" },
  { 7170, "MPL_IPI_3_SET_2" },
  { 7171, "MPL_IPI_3_SET_3" },
  { 7172, "MPL_IPI_3" },
  { 7173, "IPI_EVENT_3" },
  { 7174, "IPI_EVENT_RESET_3" },
  { 7175, "IPI_EVENT_SET_3" },
  { 7176, "IPI_MASK_3" },
  { 7177, "IPI_MASK_RESET_3" },
  { 7178, "IPI_MASK_SET_3" },
  { 7424, "MPL_IPI_2_SET_0" },
  { 7425, "MPL_IPI_2_SET_1" },
  { 7426, "MPL_IPI_2_SET_2" },
  { 7427, "MPL_IPI_2_SET_3" },
  { 7428, "MPL_IPI_2" },
  { 7429, "IPI_EVENT_2" },
  { 7430, "IPI_EVENT_RESET_2" },
  { 7431, "IPI_EVENT_SET_2" },
  { 7432, "IPI_MASK_2" },
  { 7433, "IPI_MASK_RESET_2" },
  { 7434, "IPI_MASK_SET_2" },
  { 7680, "MPL_IPI_1_SET_0" },
  { 7681, "MPL_IPI_1_SET_1" },
  { 7682, "MPL_IPI_1_SET_2" },
  { 7683, "MPL_IPI_1_SET_3" },
  { 7684, "MPL_IPI_1" },
  { 7685, "IPI_EVENT_1" },
  { 7686, "IPI_EVENT_RESET_1" },
  { 7687, "IPI_EVENT_SET_1" },
  { 7688, "IPI_MASK_1" },
  { 7689, "IPI_MASK_RESET_1" },
  { 7690, "IPI_MASK_SET_1" },
  { 7936, "MPL_IPI_0_SET_0" },
  { 7937, "MPL_IPI_0_SET_1" },
  { 7938, "MPL_IPI_0_SET_2" },
  { 7939, "MPL_IPI_0_SET_3" },
  { 7940, "MPL_IPI_0" },
  { 7941, "IPI_EVENT_0" },
  { 7942, "IPI_EVENT_RESET_0" },
  { 7943, "IPI_EVENT_SET_0" },
  { 7944, "IPI_MASK_0" },
  { 7945, "IPI_MASK_RESET_0" },
  { 7946, "IPI_MASK_SET_0" },
  { 8192, "MPL_PERF_COUNT_SET_0" },
  { 8193, "MPL_PERF_COUNT_SET_1" },
  { 8194, "MPL_PERF_COUNT_SET_2" },
  { 8195, "MPL_PERF_COUNT_SET_3" },
  { 8196, "MPL_PERF_COUNT" },
  { 8197, "PERF_COUNT_0" },
  { 8198, "PERF_COUNT_1" },
  { 8199, "PERF_COUNT_CTL" },
  { 8200, "PERF_COUNT_DN_CTL" },
  { 8201, "PERF_COUNT_STS" },
  { 8202, "WATCH_MASK" },
  { 8203, "WATCH_VAL" },
  { 8448, "MPL_AUX_PERF_COUNT_SET_0" },
  { 8449, "MPL_AUX_PERF_COUNT_SET_1" },
  { 8450, "MPL_AUX_PERF_COUNT_SET_2" },
  { 8451, "MPL_AUX_PERF_COUNT_SET_3" },
  { 8452, "MPL_AUX_PERF_COUNT" },
  { 8453, "AUX_PERF_COUNT_0" },
  { 8454, "AUX_PERF_COUNT_1" },
  { 8455, "AUX_PERF_COUNT_CTL" },
  { 8456, "AUX_PERF_COUNT_STS" },
  { 8704, "MPL_INTCTRL_3_SET_0" },
  { 8705, "MPL_INTCTRL_3_SET_1" },
  { 8706, "MPL_INTCTRL_3_SET_2" },
  { 8707, "MPL_INTCTRL_3_SET_3" },
  { 8708, "MPL_INTCTRL_3" },
  { 8709, "INTCTRL_3_STATUS" },
  { 8710, "INTERRUPT_MASK_3" },
  { 8711, "INTERRUPT_MASK_RESET_3" },
  { 8712, "INTERRUPT_MASK_SET_3" },
  { 8713, "INTERRUPT_VECTOR_BASE_3" },
  { 8714, "SINGLE_STEP_EN_0_3" },
  { 8715, "SINGLE_STEP_EN_1_3" },
  { 8716, "SINGLE_STEP_EN_2_3" },
  { 8717, "SINGLE_STEP_EN_3_3" },
  { 8832, "EX_CONTEXT_3_0" },
  { 8833, "EX_CONTEXT_3_1" },
  { 8834, "SYSTEM_SAVE_3_0" },
  { 8835, "SYSTEM_SAVE_3_1" },
  { 8836, "SYSTEM_SAVE_3_2" },
  { 8837, "SYSTEM_SAVE_3_3" },
  { 8960, "MPL_INTCTRL_2_SET_0" },
  { 8961, "MPL_INTCTRL_2_SET_1" },
  { 8962, "MPL_INTCTRL_2_SET_2" },
  { 8963, "MPL_INTCTRL_2_SET_3" },
  { 8964, "MPL_INTCTRL_2" },
  { 8965, "INTCTRL_2_STATUS" },
  { 8966, "INTERRUPT_MASK_2" },
  { 8967, "INTERRUPT_MASK_RESET_2" },
  { 8968, "INTERRUPT_MASK_SET_2" },
  { 8969, "INTERRUPT_VECTOR_BASE_2" },
  { 8970, "SINGLE_STEP_EN_0_2" },
  { 8971, "SINGLE_STEP_EN_1_2" },
  { 8972, "SINGLE_STEP_EN_2_2" },
  { 8973, "SINGLE_STEP_EN_3_2" },
  { 9088, "EX_CONTEXT_2_0" },
  { 9089, "EX_CONTEXT_2_1" },
  { 9090, "SYSTEM_SAVE_2_0" },
  { 9091, "SYSTEM_SAVE_2_1" },
  { 9092, "SYSTEM_SAVE_2_2" },
  { 9093, "SYSTEM_SAVE_2_3" },
  { 9216, "MPL_INTCTRL_1_SET_0" },
  { 9217, "MPL_INTCTRL_1_SET_1" },
  { 9218, "MPL_INTCTRL_1_SET_2" },
  { 9219, "MPL_INTCTRL_1_SET_3" },
  { 9220, "MPL_INTCTRL_1" },
  { 9221, "INTCTRL_1_STATUS" },
  { 9222, "INTERRUPT_MASK_1" },
  { 9223, "INTERRUPT_MASK_RESET_1" },
  { 9224, "INTERRUPT_MASK_SET_1" },
  { 9225, "INTERRUPT_VECTOR_BASE_1" },
  { 9226, "SINGLE_STEP_EN_0_1" },
  { 9227, "SINGLE_STEP_EN_1_1" },
  { 9228, "SINGLE_STEP_EN_2_1" },
  { 9229, "SINGLE_STEP_EN_3_1" },
  { 9344, "EX_CONTEXT_1_0" },
  { 9345, "EX_CONTEXT_1_1" },
  { 9346, "SYSTEM_SAVE_1_0" },
  { 9347, "SYSTEM_SAVE_1_1" },
  { 9348, "SYSTEM_SAVE_1_2" },
  { 9349, "SYSTEM_SAVE_1_3" },
  { 9472, "MPL_INTCTRL_0_SET_0" },
  { 9473, "MPL_INTCTRL_0_SET_1" },
  { 9474, "MPL_INTCTRL_0_SET_2" },
  { 9475, "MPL_INTCTRL_0_SET_3" },
  { 9476, "MPL_INTCTRL_0" },
  { 9477, "INTCTRL_0_STATUS" },
  { 9478, "INTERRUPT_MASK_0" },
  { 9479, "INTERRUPT_MASK_RESET_0" },
  { 9480, "INTERRUPT_MASK_SET_0" },
  { 9481, "INTERRUPT_VECTOR_BASE_0" },
  { 9482, "SINGLE_STEP_EN_0_0" },
  { 9483, "SINGLE_STEP_EN_1_0" },
  { 9484, "SINGLE_STEP_EN_2_0" },
  { 9485, "SINGLE_STEP_EN_3_0" },
  { 9600, "EX_CONTEXT_0_0" },
  { 9601, "EX_CONTEXT_0_1" },
  { 9602, "SYSTEM_SAVE_0_0" },
  { 9603, "SYSTEM_SAVE_0_1" },
  { 9604, "SYSTEM_SAVE_0_2" },
  { 9605, "SYSTEM_SAVE_0_3" },
  { 9728, "MPL_BOOT_ACCESS_SET_0" },
  { 9729, "MPL_BOOT_ACCESS_SET_1" },
  { 9730, "MPL_BOOT_ACCESS_SET_2" },
  { 9731, "MPL_BOOT_ACCESS_SET_3" },
  { 9732, "MPL_BOOT_ACCESS" },
  { 9733, "BIG_ENDIAN_CONFIG" },
  { 9734, "CACHE_INVALIDATION_COMPRESSION_MODE" },
  { 9735, "CACHE_INVALIDATION_MASK_0" },
  { 9736, "CACHE_INVALIDATION_MASK_1" },
  { 9737, "CACHE_INVALIDATION_MASK_2" },
  { 9738, "CBOX_CACHEASRAM_CONFIG" },
  { 9739, "CBOX_CACHE_CONFIG" },
  { 9740, "CBOX_HOME_MAP_ADDR" },
  { 9741, "CBOX_HOME_MAP_DATA" },
  { 9742, "CBOX_MMAP_0" },
  { 9743, "CBOX_MMAP_1" },
  { 9744, "CBOX_MMAP_2" },
  { 9745, "CBOX_MMAP_3" },
  { 9746, "CBOX_MSR" },
  { 9747, "DIAG_BCST_CTL" },
  { 9748, "DIAG_BCST_MASK" },
  { 9749, "DIAG_BCST_TRIGGER" },
  { 9750, "DIAG_MUX_CTL" },
  { 9751, "DIAG_TRACE_CTL" },
  { 9752, "DIAG_TRACE_DATA" },
  { 9753, "DIAG_TRACE_STS" },
  { 9754, "IDN_DEMUX_BUF_THRESH" },
  { 9755, "L1_I_PIN_WAY_0" },
  { 9756, "MEM_ROUTE_ORDER" },
  { 9757, "MEM_STRIPE_CONFIG" },
  { 9758, "PERF_COUNT_PLS" },
  { 9759, "PSEUDO_RANDOM_NUMBER_MODIFY" },
  { 9760, "QUIESCE_CTL" },
  { 9761, "RSHIM_COORD" },
  { 9762, "SBOX_CONFIG" },
  { 9763, "UDN_DEMUX_BUF_THRESH" },
  { 9764, "XDN_CORE_STARVATION_COUNT" },
  { 9765, "XDN_ROUND_ROBIN_ARB_CTL" },
  { 9856, "CYCLE_MODIFY" },
  { 9857, "I_AAR" },
  { 9984, "MPL_WORLD_ACCESS_SET_0" },
  { 9985, "MPL_WORLD_ACCESS_SET_1" },
  { 9986, "MPL_WORLD_ACCESS_SET_2" },
  { 9987, "MPL_WORLD_ACCESS_SET_3" },
  { 9988, "MPL_WORLD_ACCESS" },
  { 9989, "DONE" },
  { 9990, "DSTREAM_PF" },
  { 9991, "FAIL" },
  { 9992, "INTERRUPT_CRITICAL_SECTION" },
  { 9993, "PASS" },
  { 9994, "PSEUDO_RANDOM_NUMBER" },
  { 9995, "TILE_COORD" },
  { 9996, "TILE_RTF_HWM" },
  { 10112, "CMPEXCH_VALUE" },
  { 10113, "CYCLE" },
  { 10114, "EVENT_BEGIN" },
  { 10115, "EVENT_END" },
  { 10116, "PROC_STATUS" },
  { 10117, "SIM_CONTROL" },
  { 10118, "SIM_SOCKET" },
  { 10119, "STATUS_SATURATE" },
  { 10240, "MPL_I_ASID_SET_0" },
  { 10241, "MPL_I_ASID_SET_1" },
  { 10242, "MPL_I_ASID_SET_2" },
  { 10243, "MPL_I_ASID_SET_3" },
  { 10244, "MPL_I_ASID" },
  { 10245, "I_ASID" },
  { 10496, "MPL_D_ASID_SET_0" },
  { 10497, "MPL_D_ASID_SET_1" },
  { 10498, "MPL_D_ASID_SET_2" },
  { 10499, "MPL_D_ASID_SET_3" },
  { 10500, "MPL_D_ASID" },
  { 10501, "D_ASID" },
  { 10752, "MPL_DOUBLE_FAULT_SET_0" },
  { 10753, "MPL_DOUBLE_FAULT_SET_1" },
  { 10754, "MPL_DOUBLE_FAULT_SET_2" },
  { 10755, "MPL_DOUBLE_FAULT_SET_3" },
  { 10756, "MPL_DOUBLE_FAULT" },
  { 10757, "LAST_INTERRUPT_REASON" },
};

const int tilegx_num_sprs = 441;

#endif /* DISASM_ONLY */

#ifndef DISASM_ONLY

#include <stdlib.h>

static int
tilegx_spr_compare (const void *a_ptr, const void *b_ptr)
{
  const struct tilegx_spr *a = (const struct tilegx_spr *) a_ptr;
  const struct tilegx_spr *b = (const struct tilegx_spr *) b_ptr;
  return (a->number - b->number);
}

const char *
get_tilegx_spr_name (int num)
{
  void *result;
  struct tilegx_spr key;

  key.number = num;
  result = bsearch ((const void *) &key, (const void *) tilegx_sprs,
		    tilegx_num_sprs, sizeof (struct tilegx_spr),
		    tilegx_spr_compare);

  if (result == NULL)
    return NULL;

  {
    struct tilegx_spr *result_ptr = (struct tilegx_spr *) result;

    return result_ptr->name;
  }
}

/* Canonical name of each register.  */
const char * const tilegx_register_names[] =
{
  "r0",   "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7",
  "r8",   "r9",  "r10", "r11", "r12", "r13", "r14", "r15",
  "r16",  "r17", "r18", "r19", "r20", "r21", "r22", "r23",
  "r24",  "r25", "r26", "r27", "r28", "r29", "r30", "r31",
  "r32",  "r33", "r34", "r35", "r36", "r37", "r38", "r39",
  "r40",  "r41", "r42", "r43", "r44", "r45", "r46", "r47",
  "r48",  "r49", "r50", "r51", "r52", "tp",  "sp",  "lr",
  "sn",  "idn0", "idn1", "udn0", "udn1", "udn2", "udn3", "zero"
};

#endif /* not DISASM_ONLY */


/* Given a set of bundle bits and the lookup FSM for a specific pipe,
   returns which instruction the bundle contains in that pipe.  */

static const struct tilegx_opcode *
find_opcode (tilegx_bundle_bits bits, const unsigned short *table)
{
  int i = 0;

  while (1)
    {
      unsigned short bitspec = table[i];
      unsigned int bitfield =
	((unsigned int)(bits >> (bitspec & 63))) & (bitspec >> 6);

      unsigned short next = table[i + 1 + bitfield];
      if (next <= TILEGX_OPC_NONE)
	return & tilegx_opcodes[next];

      i = next - TILEGX_OPC_NONE;
    }
}

int
parse_insn_tilegx (tilegx_bundle_bits bits,
		   unsigned long long pc,
		   struct tilegx_decoded_instruction
		   decoded[TILEGX_MAX_INSTRUCTIONS_PER_BUNDLE])
{
  int num_instructions = 0;
  int pipe;
  int min_pipe, max_pipe;

  if ((bits & TILEGX_BUNDLE_MODE_MASK) == 0)
    {
      min_pipe = TILEGX_PIPELINE_X0;
      max_pipe = TILEGX_PIPELINE_X1;
    }
  else
    {
      min_pipe = TILEGX_PIPELINE_Y0;
      max_pipe = TILEGX_PIPELINE_Y2;
    }

  /* For each pipe, find an instruction that fits.  */
  for (pipe = min_pipe; pipe <= max_pipe; pipe++)
    {
      const struct tilegx_opcode *opc;
      struct tilegx_decoded_instruction *d;
      int i;

      d = &decoded[num_instructions++];
      opc = find_opcode (bits, tilegx_bundle_decoder_fsms[pipe]);
      d->opcode = opc;

      /* Decode each operand, sign extending, etc. as appropriate.  */
      for (i = 0; i < opc->num_operands; i++)
	{
	  const struct tilegx_operand *op =
	    &tilegx_operands[opc->operands[pipe][i]];
	  int raw_opval = op->extract (bits);
	  long long opval;

	  if (op->is_signed)
	    {
	      /* Sign-extend the operand.  */
	      int shift = (int)((sizeof(int) * 8) - op->num_bits);
	      raw_opval = (raw_opval << shift) >> shift;
	    }

	  /* Adjust PC-relative scaled branch offsets.  */
	  if (op->type == TILEGX_OP_TYPE_ADDRESS)
	    opval = (raw_opval * TILEGX_BUNDLE_SIZE_IN_BYTES) + pc;
	  else
	    opval = raw_opval;

	  /* Record the final value.  */
	  d->operands[i] = op;
	  d->operand_values[i] = opval;
	}
    }

  return num_instructions;
}
