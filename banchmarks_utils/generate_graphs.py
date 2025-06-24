#!/usr/bin/env python3
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os
import sys

def generate_graphs(csv_file):
    try:
        df = pd.read_csv(csv_file)
        df[['Program', 'Type']] = df['command'].str.extract(r'([^\/]+)_(normal|fip)')

        mean_pivot = df.pivot(index='Program', columns='Type', values='mean')
        stddev_pivot = df.pivot(index='Program', columns='Type', values='stddev')
        fetch_pivot = df.pivot(index='Program', columns='Type', values='fetch_time')
        speedup = (mean_pivot['normal']) / (mean_pivot['fip'])

        plt.figure(figsize=(12, 10))

        programs = mean_pivot.index
        x = np.arange(len(programs))
        width = 0.35

        ax1 = plt.subplot(2, 1, 1)
        rects1 = ax1.bar(x - width/2, mean_pivot['normal'], width,
                        label='Normal', yerr=stddev_pivot['normal'],
                        error_kw=dict(capsize=5))
        rects2 = ax1.bar(x + width/2, mean_pivot['fip'], width,
                        label='FIP', yerr=stddev_pivot['fip'],
                        error_kw=dict(capsize=5))
        rects3 = ax1.bar(x, fetch_pivot['fip'], width * 2 - (width / 20),
                        label='Data Fetch', color= (0.5, 0.5, 0.5),
                        error_kw=dict(capsize=5))

        ax1.set_title('Execution Time Comparison (in seconds)', pad=20)
        ax1.set_ylabel('Time (seconds)')
        ax1.set_xticks(x)
        ax1.set_xticklabels(programs, rotation=45, ha='right')
        ax1.legend()
        ax1.grid(True, axis='y', linestyle='--', alpha=0.6)

        def autolabel(rects):
            for rect in rects:
                height = rect.get_height()
                ax1.annotate(f'{height:.4f}',
                            xy=(rect.get_x() + rect.get_width() / 2, height),
                            xytext=(0, 3),  # 3 points vertical offset
                            textcoords="offset points",
                            ha='center', va='bottom', fontsize=8)
        autolabel(rects1)
        autolabel(rects2)
        autolabel(rects3)

        ax2 = plt.subplot(2, 1, 2)
        speedup_plot = ax2.bar(x, speedup, width=0.6)
        ax2.axhline(1, color='red', linestyle='--')

        for idx, rect in enumerate(speedup_plot):
            height = rect.get_height()
            ax2.text(rect.get_x() + rect.get_width()/2, height,
                    f'{height:.2f}x', ha='center', va='bottom', fontsize=9)
        
        ax2.set_title('Speedup Ratio ( Normal/FIP )', pad=20)
        ax2.set_ylabel('Speedup Factor')
        ax2.set_xticks(x)
        ax2.set_xticklabels(programs, rotation=45, ha='right')
        ax2.grid(True, axis='y', linestyle='--', alpha=0.6)

        plt.tight_layout()
        output_file = os.path.splitext(csv_file)[0] + '_comparison.png'
        plt.savefig(output_file, dpi=300, bbox_inches='tight')
        print(f"Successfully generated: {output_file}")

    except Exception as e:
        print(f"Error generating graphs: {str(e)}")
        if 'df' in locals():
            print("CSV columns found:", df.columns.tolist())
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python generate_graphs.py <benchmark_results.csv>")
        sys.exit(1)
    
    generate_graphs(sys.argv[1])