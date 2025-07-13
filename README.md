# Combine OrthoGroup Sets (COGS)
This repository hosts the updated version of the Combine OrthoGroup Sets (COGS), which was initially developed for the Klebsormidiophyceae phylogenomic study. As the tool has grown and gained more features over time, I've decided to maintain each tool for the PhyloRSeq++ pipeline in its own dedicated GitHub repository for clarity and modularity.
This tool merges two sets of orthogroup FASTA files by interpreting and combining orthogroup names, removing duplicates, and organizing the combined dataset based on OrthoFinder output files. It can optionally reformat FASTA headers into a format compatible with Phylopypruner.

---

## Overview

- Runs efficiently on a single CPU.
- Output files are limited to under 1 GB RAM usage.
- Compatible with any 64-bit machine.
- Fast execution: ~5% of time parsing/calculating, ~95% writing files.
- Performance depends heavily on disk and network speed.
- To adjust output file size limits, contact:  
  maaikejacobine.bierenbroodspot@uni-goettingen.de

---

## How It Works

There are two ways to run this tool:

### Method 1

1. Parses orthogroup names from two input FASTA sets and removes duplicates.  
2. Uses OrthoFinder output (TSV format) to map and combine orthogroup sequences.  
3. Writes the merged FASTA files to the specified output folder.  
4. Optionally reformats FASTA headers for compatibility with Phylopypruner.

> **Important:**  
> After running COGS with this method, you must rerun MIAF since you will not have MSA or tree files. The results will be similar to the output from the [Orthogroup Sequence Grabber](https://github.com/mjbieren/OrthoGroup_Sequence_Grabber).

### Method 2

1. Parses orthogroup names from the **output folders** of Phylopypruner (Outgroup and Ingroup sets) and removes duplicate orthogroup names.  
2. Matches orthogroup files in the **input folders** for Phylopypruner (Outgroup and Ingroup sets) and copies the tree and MSA files to the output folder.

---

### Recommendation

Method 2 is preferred as it significantly reduces computational resources and runtime for the entire pipeline. Use Method 1 only if you need to examine the raw orthogroup sequences (i.e., before Phylopypruner processing).


## Executables

Built with Boost Library (v1.88) and developed in Visual Studio 2019 with GCC compiler for Linux.  
Portable executables available for:

- Debian 12: [COGS_Debian.out](https://github.com/mjbieren/Phylogenomics_klebsormidiophyceae/tree/main/Executables/COGS)  
- Rocky Linux 8 (Red Hat based): [COGS_HPC.out](https://github.com/mjbieren/Phylogenomics_klebsormidiophyceae/tree/main/Executables/COGS)  

Alternatively, you can compile your own executable from the source files.

---

## Usage

Method 1
```
COGS_Static.out -f <SourceFileBase> -s <PathToFirstSet> -t <PathToSecondSet> -o <OrthoFinderOutput> -r <OutputDir> [-p]
```

Method 2
```
COGS_Static.out -s <PPP_INGROUP_OUTPUT> -x <PPP_INGROUP_INPUT> -t <FPPP_OUTGROUP_OUTPUT> -y <PPP_OUTGROUP_INPUT> [-p]
```

## Options

| Flag            | Description                                                                                       |
|-----------------|-------------------------------------------------------------------------------------------------|
| `-f <FastaFilesBase>`    | Path to the directory containing your FASTA files. **Required METHOD 1**                               |
| `-s <FastaFileFirstSet>` | Path to the first orthogroup set in FASTA format. **Required**                                |
| `-t <FastaFileSecondSet>`| Path to the second orthogroup set in FASTA format. **Required**                               |
| `-o <OrthoGroupFilesPath>`| Path to the directory containing the Orthogroups in TSV format. **Required METHOD 1**                 |
| `-x <PPPInputDirSet1>`   | Use the PhyloPyPruner input directory for Set 1 instead of the base FASTA file. **REQUIRED METHOD 2**  |
| `-y <PPPInputDirSet2>`   | Use the PhyloPyPruner input directory for Set 2 instead of the base FASTA file. **REQUIRED METHOD 2**  |
| `-r <OutputDirPath>`     | Path to the directory where the output files will be written. **Required**                    |
| `-p`                    | Reformat all FASTA headers to the format needed for PhyloPyPruner. **Optional** (default: keep original headers) |

