#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>

// 函数声明

// 主菜单显示函数
// 显示程序的主菜单界面,包括硬件信息读取、健康状态检测、温度监控和帮助文档等选项
void showMainMenu(void);

// 硬件信息菜单显示函数
// 显示硬件信息相关的子菜单,包括CPU信息、内存信息和硬盘信息的查看选项
void showHardwareInfoMenu(void);

// 硬件健康状态菜单显示函数
// 显示硬件健康状态检测的子菜单,包括SMART监测和电池健康状态检测选项
void showHealthCheckMenu(void);

// 温度监控菜单显示函数
// 显示温度监控相关的子菜单,提供开始监控温度的选项
void showTemperatureMenu(void);

// 帮助菜单显示函数
// 显示帮助相关的子菜单,包括用户手册和帮助命令的查看选项
void showHelpMenu(void);

// 硬件信息相关函数
// CPU信息获取函数
// 通过读取/proc/cpuinfo和/proc/loadavg文件获取CPU的详细信息
// 包括处理器型号、核心数、频率、缓存大小和CPU负载等信息
void getCPUInfo(void);

// 内存信息获取函数
// 通过读取/proc/meminfo文件获取内存使用情况
// 包括物理内存和交换空间的总量、已用量、可用量等信息
void getMemoryInfo(void);

// 硬盘信息获取函数
// 通过读取/proc/mounts文件和使用statvfs系统调用获取磁盘使用情况
// 显示各个分区的总容量、可用容量和使用率等信息
void getDiskInfo(void);

// 硬件健康状态相关函数
// SMART硬盘健康检测函数
// 使用smartctl工具检查硬盘的SMART状态
// 显示硬盘健康状态、温度和重要SMART属性值
void checkSMART(void);

// 电池健康状态检测函数
// 通过读取/sys/class/power_supply下的文件获取电池信息
// 显示电池状态、容量、循环次数、电压等信息,并评估电池健康度
void checkBatteryHealth(void);

// 温度监控相关函数
// 温度监控函数
// 实时监控CPU和硬盘温度
// 定期更新显示温度数据,并提供温度预警提示
void monitorTemperature(void);

// 帮助文档相关函数
// 用户手册显示函数
// 显示软件的详细使用说明
// 包括功能介绍、使用方法、注意事项和技术支持信息等
void showUserManual(void);

// 帮助命令显示函数
// 显示Linux系统下常用的硬件信息查看命令
// 包括CPU、内存、硬盘、网络等相关命令的说明
void showHelpCommands(void);

int main() {
    while(1) {
        showMainMenu();
    }
    return 0;
}

void showMainMenu(void) {
    int choice;
    system("clear");  // 清屏
    
    printf("\n=== Linux硬件信息检测工具 ===\n");
    printf("1. 硬件信息读取\n");
    printf("2. 硬件健康状态检测\n");
    printf("3. 硬件温度监控\n");
    printf("4. 用户文档和帮助\n");
    printf("0. 退出程序\n");
    printf("请输入您的选择: ");
    
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            showHardwareInfoMenu();
            break;
        case 2:
            showHealthCheckMenu();
            break;
        case 3:
            showTemperatureMenu();
            break;
        case 4:
            showHelpMenu();
            break;
        case 0:
            printf("感谢使用，再见！\n");
            exit(0);
        default:
            printf("无效选择，请重试\n");
            sleep(1);
    }
}

void showHardwareInfoMenu(void) {
    int choice;
    do {
        system("clear");
        printf("\n=== 硬件信息读取 ===\n");
        printf("1. CPU信息\n");
        printf("2. 内存信息\n");
        printf("3. 硬盘信息\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                getCPUInfo();
                break;
            case 2:
                getMemoryInfo();
                break;
            case 3:
                getDiskInfo();
                break;
            case 0:
                return;
            default:
                printf("无效选择，请重试\n");
                sleep(1);
        }
    } while(1);
}

void showHealthCheckMenu(void) {
    int choice;
    do {
        system("clear");
        printf("\n=== 硬件健康状态检测 ===\n");
        printf("1. SMART监测\n");
        printf("2. 电池健康状态\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                checkSMART();
                break;
            case 2:
                checkBatteryHealth();
                break;
            case 0:
                return;
            default:
                printf("无效选择，请重试\n");
                sleep(1);
        }
    } while(1);
}

void showTemperatureMenu(void) {
    int choice;
    do {
        system("clear");
        printf("\n=== 硬件温度监控 ===\n");
        printf("1. 开始监控温度\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                monitorTemperature();
                break;
            case 0:
                return;
            default:
                printf("无效选择，请重试\n");
                sleep(1);
        }
    } while(1);
}

void showHelpMenu(void) {
    int choice;
    do {
        system("clear");
        printf("\n=== 用户文档和帮助 ===\n");
        printf("1. 用户手册\n");
        printf("2. 帮助命令\n");
        printf("0. 返回主菜单\n");
        printf("请输入您的选择: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                showUserManual();
                break;
            case 2:
                showHelpCommands();
                break;
            case 0:
                return;
            default:
                printf("无效选择，请重试\n");
                sleep(1);
        }
    } while(1);
}

// 以下是功能函数的基本实现框架
void getCPUInfo(void) {
    FILE *fp;
    char line[256];
    int cpu_count = 0;
    char cpu_model[256] = {0};
    char cpu_freq[256] = {0};
    char cache_size[256] = {0};

    printf("\n正在读取CPU信息...\n");
    
    // 打开 /proc/cpuinfo 文件
    fp = fopen("/proc/cpuinfo", "r");
    if (fp == NULL) {
        printf("无法读取CPU信息！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    // 逐行读取文件内容
    while (fgets(line, sizeof(line), fp)) {
        // 获取CPU型号
        if (strncmp(line, "model name", 10) == 0) {
            char *p = strchr(line, ':');
            if (p) {
                strcpy(cpu_model, p + 2);
                cpu_model[strlen(cpu_model)-1] = '\0'; // 删除换行符
                cpu_count++;
            }
        }
        // 获取CPU频率
        else if (strncmp(line, "cpu MHz", 7) == 0) {
            char *p = strchr(line, ':');
            if (p && strlen(cpu_freq) == 0) {
                strcpy(cpu_freq, p + 2);
                cpu_freq[strlen(cpu_freq)-1] = '\0';
            }
        }
        // 获取缓存大小
        else if (strncmp(line, "cache size", 10) == 0) {
            char *p = strchr(line, ':');
            if (p && strlen(cache_size) == 0) {
                strcpy(cache_size, p + 2);
                cache_size[strlen(cache_size)-1] = '\0';
            }
        }
    }

    // 关闭文件
    fclose(fp);

    // 显示CPU信息
    printf("\n=== CPU信息 ===\n");
    printf("处理器型号: %s\n", cpu_model);
    printf("核心数量: %d\n", cpu_count);
    printf("当前频率: %s MHz\n", cpu_freq);
    printf("缓存大小: %s\n", cache_size);

    // 获取CPU负载信息
    fp = fopen("/proc/loadavg", "r");
    if (fp != NULL) {
        float load1, load5, load15;
        if (fscanf(fp, "%f %f %f", &load1, &load5, &load15) == 3) {
            printf("\nCPU负载情况:\n");
            printf("1分钟平均负载: %.2f\n", load1);
            printf("5分钟平均负载: %.2f\n", load5);
            printf("15分钟平均负载: %.2f\n", load15);
        }
        fclose(fp);
    }

    printf("\n按回车键返回...");
    getchar();
    getchar();
}

void getMemoryInfo(void) {
    FILE *fp;
    char line[256];
    unsigned long total_mem = 0;
    unsigned long free_mem = 0;
    unsigned long available_mem = 0;
    unsigned long buffers = 0;
    unsigned long cached = 0;
    unsigned long swap_total = 0;
    unsigned long swap_free = 0;

    printf("\n正在读取内存信息...\n");
    
    // 打开 /proc/meminfo 文件
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        printf("无法读取内存信息！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    // 逐行读取文件内容
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "MemTotal:", 9) == 0)
            sscanf(line, "MemTotal: %lu kB", &total_mem);
        else if (strncmp(line, "MemFree:", 8) == 0)
            sscanf(line, "MemFree: %lu kB", &free_mem);
        else if (strncmp(line, "MemAvailable:", 13) == 0)
            sscanf(line, "MemAvailable: %lu kB", &available_mem);
        else if (strncmp(line, "Buffers:", 8) == 0)
            sscanf(line, "Buffers: %lu kB", &buffers);
        else if (strncmp(line, "Cached:", 7) == 0)
            sscanf(line, "Cached: %lu kB", &cached);
        else if (strncmp(line, "SwapTotal:", 10) == 0)
            sscanf(line, "SwapTotal: %lu kB", &swap_total);
        else if (strncmp(line, "SwapFree:", 9) == 0)
            sscanf(line, "SwapFree: %lu kB", &swap_free);
    }

    fclose(fp);

    // 计算使用的内存和交换空间
    unsigned long used_mem = total_mem - free_mem - buffers - cached;
    unsigned long used_swap = swap_total - swap_free;

    // 显示内存信息
    printf("\n=== 内存信息 ===\n");
    printf("总物理内存：    %.2f GB\n", total_mem / 1024.0 / 1024.0);
    printf("已用物理内存：  %.2f GB\n", used_mem / 1024.0 / 1024.0);
    printf("可用物理内存：  %.2f GB\n", available_mem / 1024.0 / 1024.0);
    printf("缓冲区：        %.2f GB\n", buffers / 1024.0 / 1024.0);
    printf("缓存：          %.2f GB\n", cached / 1024.0 / 1024.0);
    printf("\n=== 交换空间 ===\n");
    printf("总交换空间：    %.2f GB\n", swap_total / 1024.0 / 1024.0);
    printf("已用交换空间：  %.2f GB\n", used_swap / 1024.0 / 1024.0);
    printf("可用交换空间：  %.2f GB\n", swap_free / 1024.0 / 1024.0);

    // 显示内存使用率
    float mem_usage = ((float)used_mem / total_mem) * 100;
    float swap_usage = swap_total ? ((float)used_swap / swap_total) * 100 : 0;
    
    printf("\n=== 使用率 ===\n");
    printf("物理内存使用率：%.1f%%\n", mem_usage);
    printf("交换空间使用率：%.1f%%\n", swap_usage);

    printf("\n按回车键返回...");
    getchar();
    getchar();
}

void getDiskInfo(void) {
    FILE *fp;
    char line[512];
    char device[256], mountpoint[256], fstype[256];
    struct statvfs stat;
    
    printf("\n=== 磁盘信息 ===\n");
    
    // 打开/proc/mounts文件
    fp = fopen("/proc/mounts", "r");
    if (fp == NULL) {
        printf("无法读取磁盘信息！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    // 修改表头格式，增加字段宽度
    printf("\n%-12s %-20s %-12s %15s %15s %10s\n", 
           "设备", "挂载点", "文件系统", "总容量(GB)", "可用容量(GB)", "使用率");
    printf("--------------------------------------------------------------------------------\n");

    // 读取每个挂载点的信息
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %s %s", device, mountpoint, fstype);
        
        // 跳过一些特殊的文件系统
        if (strncmp(fstype, "proc", 4) == 0 || 
            strncmp(fstype, "sysfs", 5) == 0 || 
            strncmp(fstype, "devpts", 6) == 0 ||
            strncmp(fstype, "tmpfs", 5) == 0 ||
            strncmp(device, "/dev/loop", 9) == 0) {
            continue;
        }

        if (statvfs(mountpoint, &stat) == 0) {
            unsigned long long total_size = (unsigned long long)stat.f_blocks * stat.f_frsize;
            unsigned long long avail_size = (unsigned long long)stat.f_bavail * stat.f_frsize;
            unsigned long long used_size = total_size - (unsigned long long)stat.f_bfree * stat.f_frsize;
            
            // 转换为GB
            double total_gb = (double)total_size / (1024 * 1024 * 1024);
            double avail_gb = (double)avail_size / (1024 * 1024 * 1024);
            
            // 计算使用率
            double usage = 0;
            if (total_size > 0) {
                usage = ((double)used_size / total_size) * 100;
            }

            // 获取设备名称的最后部分
            char *short_device = strrchr(device, '/');
            if (short_device == NULL) {
                short_device = device;
            } else {
                short_device++;
            }

            // 修改输出格式，调整对齐和字段宽度
            printf("%-12s %-20.20s %-12s %15.2f %15.2f %9.1f%%\n",
                   short_device,
                   mountpoint,
                   fstype,
                   total_gb,
                   avail_gb,
                   usage);
        }
    }

    fclose(fp);

    printf("\n按回车键返回...");
    getchar();
    getchar();
}

void checkSMART(void) {
    FILE *fp;
    char line[256];
    char command[256];
    char devices[16][32];  // 存储设备名称数组
    int device_count = 0;
    int choice;

    printf("\n正在检查硬盘SMART状态...\n");

    // 检查是否安装了smartmontools
    if (system("which smartctl > /dev/null 2>&1") != 0) {
        printf("错误：未安装smartmontools。\n");
        printf("请使用以下命令安装：sudo yum install smartmontools\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    // 获取系统中的硬盘设备列表
    fp = popen("lsblk -d -o NAME | grep -E '^sd|^nvme'", "r");
    if (fp == NULL) {
        printf("无法获取硬盘设备列表！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    printf("\n检测到以下硬盘设备：\n");
    while (fgets(line, sizeof(line), fp) && device_count < 16) {
        line[strcspn(line, "\n")] = 0;  // 删除换行符
        strncpy(devices[device_count], line, 31);
        devices[device_count][31] = '\0';
        printf("%d. /dev/%s\n", device_count + 1, devices[device_count]);
        device_count++;
    }
    pclose(fp);

    if (device_count == 0) {
        printf("未检测到任何硬盘设备！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    printf("\n请选择要检查的硬盘 (1-%d): ", device_count);
    scanf("%d", &choice);

    if (choice < 1 || choice > device_count) {
        printf("无效的选择！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    // 构建smartctl命令，获取健康状态和温度信息
    snprintf(command, sizeof(command), 
             "sudo smartctl -H -A /dev/%s | grep -E 'SMART Health Status|Temperature|==='", 
             devices[choice-1]);

    // 执行SMART检测
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("执行SMART检测失败！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    printf("\n=== SMART数据读取开始 ===\n");
    
    // 读取并翻译输出结果
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "SMART Health Status")) {
            char status[32];
            sscanf(line, "SMART Health Status: %s", status);
            printf("SMART健康状态: %s\n", 
                   strcmp(status, "OK") == 0 ? "正常" : status);
        }
        else if (strstr(line, "Current Drive Temperature")) {
            int temp;
            sscanf(line, "Current Drive Temperature: %d", &temp);
            printf("当前硬盘温度: %d °C\n", temp);
        }
        else if (strstr(line, "Drive Trip Temperature")) {
            int temp;
            sscanf(line, "Drive Trip Temperature: %d", &temp);
            printf("硬盘警告温度: %d °C\n", temp);
        }
    }
    pclose(fp);

    printf("\n=== SMART值说明 ===\n");
    printf("1. 健康状态：\n");
    printf("   - 正常：硬盘工作正常\n");
    printf("   - FAILED：硬盘可能存在严重问题，建议及时备份数据\n\n");
    
    printf("2. 温度说明：\n");
    printf("   - 正常范围：0-45°C\n");
    printf("   - 警告范围：46-55°C\n");
    printf("   - 危险范围：>55°C\n\n");

    // 获取详细的SMART属性
    snprintf(command, sizeof(command), 
             "sudo smartctl -A /dev/%s | grep -E 'ID#|Reallocated|Spin|Seek|Power_On|Start_Stop|Load_Cycle'", 
             devices[choice-1]);
    
    fp = popen(command, "r");
    if (fp != NULL) {
        printf("=== 重要SMART属性 ===\n");
        printf("%-8s %-30s %-10s %-10s %-10s\n", 
               "ID", "属性名称", "当前值", "最差值", "阈值");
        printf("--------------------------------------------------------\n");
        
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "ID#")) continue;  // 跳过表头
            
            int id, current, worst, thresh;
            char name[31];
            if (sscanf(line, "%d %30s %d %d %d", &id, name, &current, &worst, &thresh) == 5) {
                printf("%-8d %-30s %-10d %-10d %-10d", id, name, current, worst, thresh);
                if (current <= thresh) {
                    printf(" [警告]");
                }
                printf("\n");
            }
        }
        pclose(fp);
    }

    printf("\n按回车键返回...");
    getchar();
    getchar();
}

void checkBatteryHealth(void) {
    FILE *fp;
    char path[256];
    char line[256];
    int present = 0;
    int capacity = 0;
    int cycle_count = 0;
    char status[64] = {0};
    long voltage_now = 0;
    long current_now = 0;
    long energy_full = 0;
    long energy_full_design = 0;

    printf("\n正在检查电池健康状态...\n");

    // 检查电池是否存在
    if (access("/sys/class/power_supply/BAT0", F_OK) != 0) {
        printf("未检测到电池设备！\n");
        printf("\n按回车键返回...");
        getchar();
        getchar();
        return;
    }

    // 读取电池状态
    snprintf(path, sizeof(path), "/sys/class/power_supply/BAT0/status");
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%s", status);
        fclose(fp);
    }

    // 读取当前电量
    snprintf(path, sizeof(path), "/sys/class/power_supply/BAT0/capacity");
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%d", &capacity);
        fclose(fp);
    }

    // 读取循环次数
    snprintf(path, sizeof(path), "/sys/class/power_supply/BAT0/cycle_count");
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%d", &cycle_count);
        fclose(fp);
    }

    // 读取当前电压（微伏）
    snprintf(path, sizeof(path), "/sys/class/power_supply/BAT0/voltage_now");
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%ld", &voltage_now);
        fclose(fp);
    }

    // 读取当前电流（微安）
    snprintf(path, sizeof(path), "/sys/class/power_supply/BAT0/current_now");
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%ld", &current_now);
        fclose(fp);
    }

    // 读取实际最大容量（微瓦时）
    snprintf(path, sizeof(path), "/sys/class/power_supply/BAT0/energy_full");
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%ld", &energy_full);
        fclose(fp);
    }

    // 读取设计最大容量（微瓦时）
    snprintf(path, sizeof(path), "/sys/class/power_supply/BAT0/energy_full_design");
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%ld", &energy_full_design);
        fclose(fp);
    }

    // 计算电池健康度
    float health_percentage = 0;
    if (energy_full_design > 0) {
        health_percentage = ((float)energy_full / energy_full_design) * 100;
    }

    // 显示电池信息
    printf("\n=== 电池状态信息 ===\n");
    printf("当前状态: %s\n", status);
    printf("当前电量: %d%%\n", capacity);
    printf("循环次数: %d\n", cycle_count);
    printf("当前电压: %.2f V\n", voltage_now / 1000000.0);
    printf("当前电流: %.2f mA\n", current_now / 1000.0);
    printf("实际容量: %.2f Wh\n", energy_full / 1000000.0);
    printf("设计容量: %.2f Wh\n", energy_full_design / 1000000.0);
    printf("电池健康度: %.1f%%\n", health_percentage);

    // 评估电池状态
    printf("\n=== 电池健康评估 ===\n");
    if (health_percentage >= 80) {
        printf("电池状态: 良好\n");
    } else if (health_percentage >= 60) {
        printf("电池状态: 一般\n");
        printf("建议: 继续使用，但需要注意电池使用时间可能会减少\n");
    } else {
        printf("电池状态: 较差\n");
        printf("建议: 考虑更换电池\n");
    }

    if (cycle_count > 500) {
        printf("提示: 电池循环次数较多，可能会影响使用时间\n");
    }

    printf("\n按回车键返回...");
    getchar();
    getchar();
}

void monitorTemperature(void) {
    FILE *fp;
    char line[256];
    float temp;
    int monitoring = 1;
    char command[256];
    int update_interval = 2; // 更新间隔（秒）
    int count = 0;
    
    // 检查是否在虚拟机环境中
    fp = popen("systemd-detect-virt 2>/dev/null || dmidecode -s system-manufacturer 2>/dev/null", "r");
    if (fp != NULL) {
        if (fgets(line, sizeof(line), fp)) {
            if (strstr(line, "vmware") || strstr(line, "VMware") || 
                strstr(line, "VirtualBox") || strstr(line, "KVM") || 
                strstr(line, "QEMU")) {
                printf("\n警告：检测到当前运行在虚拟机环境中。\n");
                printf("虚拟机可能无法准确读取CPU温度。\n");
                printf("硬盘温度监控仍然可用。\n\n");
                printf("按回车键继续...");
                getchar();
                getchar();
            }
        }
        pclose(fp);
    }
    
    printf("\n开始监控温度（按Ctrl+C退出）...\n\n");
    printf("更新间隔：%d秒\n", update_interval);
    
    while (monitoring) {
        system("clear");
        printf("\n=== 硬件温度监控 ===\n");
        printf("运行时间：%d秒\n", count * update_interval);
        
        // 获取CPU温度
        printf("\nCPU温度：\n");
        const char *temp_paths[] = {
            "/sys/class/thermal/thermal_zone0/temp",
            "/sys/class/hwmon/hwmon0/temp1_input",
            "/sys/class/hwmon/hwmon1/temp1_input",
            "/sys/class/hwmon/hwmon2/temp1_input"
        };
        
        int found_temp = 0;
        for (int i = 0; i < sizeof(temp_paths)/sizeof(temp_paths[0]); i++) {
            fp = fopen(temp_paths[i], "r");
            if (fp != NULL) {
                if (fgets(line, sizeof(line), fp)) {
                    long temp_raw;
                    sscanf(line, "%ld", &temp_raw);
                    temp = temp_raw / 1000.0;
                    printf("Core: %.1f°C ", temp);
                    
                    if (temp > 80) {
                        printf("【危险】");
                    } else if (temp > 70) {
                        printf("【警告】");
                    } else {
                        printf("【正常】");
                    }
                    printf("\n");
                    found_temp = 1;
                }
                fclose(fp);
                if (found_temp) break;
            }
        }
        
        if (!found_temp) {
            printf("无法读取CPU温度（可能是虚拟机环境限制）\n");
        }

        // 获取硬盘温度
        printf("\n硬盘温度：\n");
        fp = popen("lsblk -d -o NAME | grep -E '^sd|^nvme'", "r");
        if (fp != NULL) {
            while (fgets(line, sizeof(line), fp)) {
                line[strcspn(line, "\n")] = 0;
                
                snprintf(command, sizeof(command), 
                        "sudo smartctl -A /dev/%s | grep Temperature_Celsius | awk '{print $10}'",
                        line);
                
                FILE *temp_fp = popen(command, "r");
                if (temp_fp != NULL) {
                    if (fgets(line, sizeof(line), temp_fp)) {
                        sscanf(line, "%f", &temp);
                        printf("/dev/%s: %.1f°C ", line, temp);
                        
                        if (temp > 55) {
                            printf("【危险】");
                        } else if (temp > 45) {
                            printf("【警告】");
                        } else {
                            printf("【正常】");
                        }
                        printf("\n");
                    }
                    pclose(temp_fp);
                }
            }
            pclose(fp);
        }

        printf("\n温度状态说明：\n");
        printf("CPU温度：  正常 < 70°C < 警告 < 80°C < 危险\n");
        printf("硬盘温度：正常 < 45°C < 警告 < 55°C < 危险\n");
        printf("\n注意：在虚拟机环境中，CPU温度可能无法准确读取\n");
        printf("\n按Ctrl+C退出监控\n");
        
        count++;
        sleep(update_interval);
    }
}

void showUserManual(void) {
    system("clear");  // 清屏
    printf("\n=== Linux硬件信息检测工具用户手册 ===\n\n");
    
    // 1. 基本介绍
    printf("1. 软件介绍\n");
    printf("-------------------\n");
    printf("本工具是一个用于Linux系统的硬件信息检测工具，可以帮助用户监控和了解系统硬件状态。\n");
    printf("主要功能包括硬件信息读取、健康状态检测、温度监控等。\n\n");

    // 2. 功能模块说明
    printf("2. 功能模块说明\n");
    printf("-------------------\n");
    printf("a) 硬件信息读取\n");
    printf("   - CPU信息：显示处理器型号、核心数、频率、缓存等信息\n");
    printf("   - 内存信息：显示内存使用情况、交换空间等信息\n");
    printf("   - 硬盘信息：显示存储设备的容量和使用情况\n\n");

    printf("b) 硬件健康状态检测\n");
    printf("   - SMART监测：检查硬盘健康状态和潜在问题\n");
    printf("   - 电池健康状态：检查笔记本电池的健康程度和使用情况\n\n");

    printf("c) 硬件温度监控\n");
    printf("   - 实时监控CPU和硬盘温度\n");
    printf("   - 提供温度预警功能\n\n");

    // 3. 使用说明
    printf("3. 使用说明\n");
    printf("-------------------\n");
    printf("- 使用数字键选择对应功能\n");
    printf("- 按0返回上一级菜单\n");
    printf("- 部分功能可能需要root权限\n");
    printf("- 温度监控功能按Ctrl+C退出\n\n");

    // 4. 注意事项
    printf("4. 注意事项\n");
    printf("-------------------\n");
    printf("- 使用SMART检测功能需要安装smartmontools\n");
    printf("- 温度监控功能无需安装额外软件包\n");
    printf("- 在虚拟机环境中，CPU温度监控可能不可用\n");
    printf("- 建议定期检查硬件健康状态\n");
    printf("- 当温度超过警戒值时应当及时处理\n\n");

    // 5. 故障排除
    printf("5. 常见问题解决\n");
    printf("-------------------\n");
    printf("Q: 无法获取某些硬件信息？\n");
    printf("A: 请确保以root权限运行或已安装必要的工具包\n\n");
    printf("Q: 温度显示异常？\n");
    printf("A: 请确保系统支持温度传感器读取\n\n");
    printf("Q: SMART检测失败？\n");
    printf("A: 请确保安装了smartmontools并以root权限运行\n\n");

    // 6. 技术支持
    printf("6. 技术支持\n");
    printf("-------------------\n");
    printf("如需技术支持，请通过以下方式联系：\n");
    printf("- 项目主页：https://github.com/biu-217/Linux\n");
    printf("- 问题报告：https://github.com/biu-217/Linux/blob/main/README.md\n");
    printf("- 邮件支持：HGQ217@outlook.com\n\n");

    printf("\n按回车键返回...");
    getchar();
    getchar();
}

void showHelpCommands(void) {
    system("clear");  // 清屏
    printf("\n=== 常用硬件信息查看命令 ===\n\n");

    // CPU相关命令
    printf("CPU相关命令：\n");
    printf("-------------\n");
    printf("lscpu              - 显示CPU架构信息\n");
    printf("cat /proc/cpuinfo  - 显示CPU详细信息\n");
    printf("top               - 显示CPU使用情况和进程信息\n");
    printf("mpstat            - 显示CPU性能统计信息\n");
    printf("nproc             - 显示CPU核心数\n\n");

    // 内存相关命令
    printf("内存相关命令：\n");
    printf("-------------\n");
    printf("free -h           - 显示内存使用情况（人类可读格式）\n");
    printf("cat /proc/meminfo - 显示详细内存信息\n");
    printf("vmstat            - 显示虚拟内存统计信息\n");
    printf("swapon -s         - 显示交换空间信息\n\n");

    // 硬盘相关命令
    printf("硬盘相关命令：\n");
    printf("-------------\n");
    printf("df -h             - 显示磁盘使用情况\n");
    printf("fdisk -l          - 显示磁盘分区信息（需要root权限）\n");
    printf("lsblk             - 显示块设备信息\n");
    printf("smartctl -a /dev/sdX - 显示硬盘SMART信息（需要root权限）\n");
    printf("hdparm -i /dev/sdX   - 显示硬盘参数（需要root权限）\n\n");

    // 硬件信息命令
    printf("一般硬件信息命令：\n");
    printf("-----------------\n");
    printf("lshw              - 显示硬件配置信息（需要root权限）\n");
    printf("dmidecode         - 显示DMI/SMBIOS信息（需要root权限）\n");
    printf("lspci             - 显示PCI设备信息\n");
    printf("lsusb             - 显示USB设备信息\n");
    printf("sensors           - 显示硬件传感器信息\n\n");

    // 系统监控命令
    printf("系统监控命令：\n");
    printf("-------------\n");
    printf("htop              - 交互式系统监控工具\n");
    printf("iotop             - 显示磁盘I/O使用状况（需要root权限）\n");
    printf("powertop          - 电源消耗和管理诊断工具（需要root权限）\n");
    printf("s-tui             - 终端UI系统监控工具\n\n");

    // 网络硬件命令
    printf("网络硬件命令：\n");
    printf("-------------\n");
    printf("ifconfig          - 显示网络接口信息\n");
    printf("ip addr           - 显示IP地址信息\n");
    printf("iwconfig          - 显示无线网络接口信息\n");
    printf("ethtool           - 显示网络接口卡信息（需要root权限）\n\n");

    // 工具安装命令
    printf("常用工具安装命令：\n");
    printf("-----------------\n");
    printf("sudo yum install smartmontools - 安装硬盘监控工具\n");
    printf("sudo yum install htop          - 安装htop系统监控工具\n");
    printf("sudo yum install powertop      - 安装电源管理工具\n\n");

    // 其他有用命令
    printf("其他有用命令：\n");
    printf("-------------\n");
    printf("uname -a          - 显示系统信息\n");
    printf("uptime            - 显示系统运行时间\n");
    printf("dmesg             - 显示系统启动消息\n");
    printf("journalctl        - 查看系统日志\n\n");

    printf("注意：某些命令可能需要安装额外的软件包或需要root权限才能执行。\n");
    printf("使用 'man <命令>' 可以查看任何命令的详细手册。\n");

    printf("\n按回车键返回...");
    getchar();
    getchar();
}
